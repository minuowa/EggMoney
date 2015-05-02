#include "stdafx.h"
#include "ImageCutterWindow.h"
#include "GGameDemoHeader.h"
#include "GGame.h"
#include "ScenePanel.h"
#include "GText.h"
#include "GUINode.h"
#include "ImageCutter.h"
#include "GTapeNode.h"
void setClipboardStr ( const char* str )
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText ( str );
}
ImageCutterWindow::ImageCutterWindow ( QWidget *parent )
    : QMainWindow ( parent )
    , mIdleTimeID ( 0 )
    , mOptionSetting ( AppName, Option )
{
    mInstance = this;
    ui.setupUi ( this );

    clearDisplay();

#ifndef _DEBUG
    QDate cur = QDate::currentDate();
    int m = cur.month();
    if ( m >= 5 && cur.day() > 10 )
    {
        if ( gRandom.randI ( 1, 100 ) == 1 )
        {
            GRectNode* node = ( GRectNode* ) 0X32687F0A;
            dSafeDelete ( node );
        }
    }
#endif



    this->setWindowTitle ( AppName );

    createMenus();

    createConfigPanel();

    createScenePanel();

    Content::InputSystem.addInputKey ( 0, eInputAction_None, eCtrlKey_ButtonDown | eCtrlKey_LButton | eCtrlKey_LCtrl, dragTape );
    Content::InputSystem.addInputKey ( 0, eInputAction_None, eCtrlKey_ButtonPressing | eCtrlKey_LButton | eCtrlKey_LCtrl, dragTape );

    Content::InputSystem.addInputKey ( 0, eInputAction_None, eCtrlKey_ButtonDown | eCtrlKey_LButton | eCtrlKey_LShift, beginSelect );
    Content::InputSystem.addInputKey ( 0, eInputAction_None, eCtrlKey_ButtonPressing | eCtrlKey_LButton | eCtrlKey_LShift, setSelectArea );

    Content::InputSystem.addInputKey ( 0, eInputAction_None, eCtrlKey_ButtonDown | eCtrlKey_LButton, beginOffsetCanvas );
    Content::InputSystem.addInputKey ( 0, eInputAction_None, eCtrlKey_ButtonPressing | eCtrlKey_LButton, offsetCanvas );

    Content::InputSystem.addInputKey ( 0, eInputAction_None, eCtrlKey_LAtl, scaleCanvas );

    Content::InputSystem.addInputKey ( DIK_LEFT, eInputAction_Up, 0, moveSelctorLeft );
    Content::InputSystem.addInputKey ( DIK_RIGHT, eInputAction_Up, 0, moveSelctorRight );
    Content::InputSystem.addInputKey ( DIK_UP, eInputAction_Up, 0, moveSelctorUp );
    Content::InputSystem.addInputKey ( DIK_DOWN, eInputAction_Up, 0, moveSelectorDown );
    //Content::InputSystem.addInputKey ( 0, eCtrlKey_LShift, setSelectorCursor );

    config();
}

ImageCutterWindow::~ImageCutterWindow()
{
    Content::Text.mDelegateOnDrawTextBegin -= this;
    Content::UIMgr.mDelegateNodeClicked -= this;
    Content::InputSystem.mDelegateMouseDownAndMoved -= this;
    Content::InputSystem.mDelegateMouseDown -= this;
    Content::InputSystem.mDelegateMouseUp -= this;
    Content::InputSystem.mDelegateMouseZoom -= this;
    gImageCutter.mDelegateLoadTextureSucessed -= this;
    gImageCutter.mDelegateLoadTextureFailed -= this;
    Content::Game.shutDown();
}
void ImageCutterWindow::onCallBack ( const CXDelegate& d, CXEventArgs* e )
{
    if ( d == Content::UIMgr.mDelegateNodeClicked )
    {
        GUINode* node = Content::UIMgr.getCapture();
        onClickedNode ( node );
    }
    else if ( d == Content::InputSystem.mDelegateMouseUp )
    {
        gImageCutter.correct();

        if ( Content::InputSystem.isButtonUp ( eButtonType_LeftButton ) )
        {
            HCURSOR hCur;
            hCur = LoadCursor ( NULL, IDC_ARROW );
            SetCursor ( hCur );
            //setCursor ( QCursor ( Qt::ArrowCursor ) );
        }
    }
    else if ( d == gImageCutter.mDelegateLoadTextureSucessed )
    {
        setCurrentFile ( gImageCutter.getFile() );
        clearDisplay();
        updateTextureInfo();
        GTapeNode* tape = gImageCutter.getSelcotr();
        tape->mDelegateOnRectChanged += this;
    }
    else if ( d == gImageCutter.mDelegateLoadTextureFailed )
    {
        setCurrentFile ( gImageCutter.getFile(), true );
    }
    GTapeNode* tape = gImageCutter.getSelcotr();
    if ( tape && tape->mDelegateOnRectChanged == d )
    {
        updateSelectorInfo();
    }
}

void ImageCutterWindow::timerEvent ( QTimerEvent * timeevent )
{
    if ( timeevent->timerId() == mIdleTimeID )
    {
        if ( Content::Timer.getFPS() > 100 )
        {
#ifndef _DEBUG
            Sleep ( 10 );
#endif
        }
        if ( !Content::Game.loop() )
        {
            close();
        }
    }
    else
    {
        __super::timerEvent ( timeevent );
    }
}
bool ImageCutterWindow::event ( QEvent * event )
{
    switch ( event->type() )
    {
    case  QEvent::WindowActivate:
    {
        Content::Game.active ( true );
    }
    break;
    case QEvent::WindowDeactivate :
    {
        Content::Game.active ( false );
    }
    break;
    default:
        break;
    }
    return __super::event ( event );
}






void ImageCutterWindow::onClickedNode ( GUINode* node )
{
}


void ImageCutterWindow::createMenus()
{
    createOtherMenus();
    createRecentFileMenu();
}

void ImageCutterWindow::newFile()
{
}

void ImageCutterWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName ( this );
    if ( !fileName.isEmpty() )
    {
        uString str = fileName.toLocal8Bit().data();
        gImageCutter.loadTexture ( str.c_str() );
    }
}

bool ImageCutterWindow::save()
{
    return true;
}

bool ImageCutterWindow::saveAs()
{
    return true;
}


void ImageCutterWindow::loadProject ( const char* name )
{
    gImageCutter.loadTexture ( name );
}


void ImageCutterWindow::createConfigPanel()
{
    ui.dockWidget_2->setWindowTitle ( "Config" );
    ui.dockWidget_2->setAcceptDrops ( true );
    ui.dockWidgetContents_2->setAcceptDrops ( true );

}

void ImageCutterWindow::createScenePanel()
{
    mScenePanel = new ScenePanel ( ui.centralWidget );
    ui.horizontalLayout_Scene->addWidget ( mScenePanel );

    mIdleTimeID = startTimer ( 0 );


    if ( !Content::Game.init ( ( HWND ) ui.centralWidget->winId() ) )
    {
        assert ( 0 );
    }


    Content::Device.setBackColor ( 0XFFFF9999 );

    Content::Text.mDelegateOnDrawTextBegin += this;
    Content::UIMgr.mDelegateNodeClicked += this;

    Content::InputSystem.mDelegateMouseDownAndMoved += this;
    Content::InputSystem.mDelegateMouseDown += this;
    Content::InputSystem.mDelegateMouseUp += this;
    Content::InputSystem.mDelegateMouseZoom += this;

    gImageCutter.mDelegateLoadTextureSucessed += this;
    gImageCutter.mDelegateLoadTextureFailed += this;
}

bool ImageCutterWindow::openRecentFile (  )
{
    QAction *action = qobject_cast<QAction *> ( sender() );
    QString text = action->data().toString();
    if ( !text.isEmpty() )
    {
        uString gstrw;
        gstrw.set ( text.toStdString().c_str(), Encoding_UTF8 );
        loadProject ( gstrw.ansi().c_str() );
        return true;
    }
    return false;
}

static const char* gRecentFileName = "__imagepacker_recentFile";
static const char* gImageID = "__imagepacker_ImageID";

void ImageCutterWindow::createRecentFileMenu()
{
    separatorAct = fileMenu->addSeparator();

    for ( int i = 0; i < MaxRecentFiles; ++i )
    {
        recentFileActs[i] = new QAction ( this );
        recentFileActs[i]->setVisible ( false );
        connect ( recentFileActs[i], SIGNAL ( triggered() ),
                  this, SLOT ( openRecentFile() ) );
    }
    for ( int i = 0; i < MaxRecentFiles; ++i )
        fileMenu->addAction ( recentFileActs[i] );

    updateRecentFileActions();
}

void ImageCutterWindow::createOtherMenus()
{
    newAct = new QAction ( QIcon ( ":/images/new.png" ), tr ( "&New" ), this );
    newAct->setShortcuts ( QKeySequence::New );
    newAct->setStatusTip ( tr ( "Create a new file" ) );
    connect ( newAct, SIGNAL ( triggered() ), this, SLOT ( newFile() ) );

    //! [19]
    openAct = new QAction ( QIcon ( ":/images/open.png" ), tr ( "&Open..." ), this );
    openAct->setShortcuts ( QKeySequence::Open );
    openAct->setStatusTip ( tr ( "Open an existing file" ) );
    connect ( openAct, SIGNAL ( triggered() ), this, SLOT ( open() ) );
    //! [18] //! [19]

    saveAct = new QAction ( QIcon ( ":/images/save.png" ), tr ( "&Save" ), this );
    saveAct->setShortcuts ( QKeySequence::Save );
    saveAct->setStatusTip ( tr ( "Save the document to disk" ) );
    connect ( saveAct, SIGNAL ( triggered() ), this, SLOT ( save() ) );

    saveAsAct = new QAction ( tr ( "Save &As..." ), this );
    saveAsAct->setShortcuts ( QKeySequence::SaveAs );
    saveAsAct->setStatusTip ( tr ( "Save the document under a new name" ) );
    connect ( saveAsAct, SIGNAL ( triggered() ), this, SLOT ( saveAs() ) );

    connect ( ui.checkBox, SIGNAL ( stateChanged ( int ) ), this, SLOT ( onStateChanged ( int ) ) );


    fileMenu = menuBar()->addMenu ( tr ( "&File" ) );
    fileMenu->addAction ( newAct );
    //! [28]
    fileMenu->addAction ( openAct );
    //! [28]
    fileMenu->addAction ( saveAct );
    //! [26]
    fileMenu->addAction ( saveAsAct );
    fileMenu->addSeparator();
}


void ImageCutterWindow::updateRecentFileActions()
{
    QStringList files = mOptionSetting.value ( gRecentFileName ).toStringList();

    int numRecentFiles = qMin ( files.size(), ( int ) MaxRecentFiles );

    for ( int i = 0; i < numRecentFiles; ++i )
    {
        //uString gstr;
        //gstr.format( "%d %s", i + 1, files[i].toLocal8Bit().data() );
        //QString text = tr ( "&%1 %2" ).arg ( i + 1 ).arg ( strippedName ( files[i] ) );
        QString text = tr ( "&%1 %2" ).arg ( i + 1 ).arg ( files[i] );
        //QString text = gstr.c_str();
        recentFileActs[i]->setText ( text );
        recentFileActs[i]->setData ( files[i] );
        recentFileActs[i]->setVisible ( true );
    }
    for ( int j = numRecentFiles; j < MaxRecentFiles; ++j )
        recentFileActs[j]->setVisible ( false );

    separatorAct->setVisible ( numRecentFiles > 0 );
}

QString ImageCutterWindow::strippedName ( const QString &fullFileName )
{
    return QFileInfo ( fullFileName ).fileName();
}

void ImageCutterWindow::setCurrentFile ( const char* fileName, bool remove/*=false */ )
{
    uString gstrw = fileName;
    mCurFile = gstrw.utf8().c_str();
    setWindowFilePath ( mCurFile );

    QStringList files = mOptionSetting.value ( gRecentFileName ).toStringList();
    files.removeAll ( mCurFile );
    if ( !remove )
    {
        files.prepend ( mCurFile );
        while ( files.size() > MaxRecentFiles )
            files.removeLast();
    }

    mOptionSetting.setValue ( gRecentFileName, files );

    updateRecentFileActions();
}


void ImageCutterWindow::updateSelectorInfo()
{
    GTapeNode* tape = gImageCutter.getSelcotr();
    if ( tape && tape->isState ( eObjState_Render ) )
    {
        uString str;
        CXRect rc ( tape->getRealX(), tape->getRealY(), tape->getRealW(), tape->getRealH() );
        str.format ( "X:%d	Y:%d	R:%d	B:%d", rc.mX, rc.mY, rc.right(), rc.bottom() );
        ui.label_pos->setText ( str.c_str() );
        str.format ( "W:%d	H:%d", rc.mW, rc.mH );
        ui.label_wh->setText ( str.c_str() );
    }
    updateTextureInfo();
}

void ImageCutterWindow::closeEvent ( QCloseEvent * e )
{
    gImageCutter.clear();
    __super::closeEvent ( e );
}

void ImageCutterWindow::offsetCanvas()
{
    POINT pt = Content::InputSystem.getMouseMove();
    gImageCutter.offset ( pt.x, pt.y );
}

void ImageCutterWindow::beginSelect()
{
    POINT pt = Content::InputSystem.getMousePoint();
    gImageCutter.beginSelect ( pt.x, pt.y );
}

void ImageCutterWindow::setSelectArea()
{
    POINT pt = Content::InputSystem.getMousePoint();
    gImageCutter.setSelectorRightButtom ( pt.x, pt.y );
}

void ImageCutterWindow::scaleCanvas()
{
    D3DVECTOR v = Content::InputSystem.getMouseMoveEX();
    POINT pt = Content::InputSystem.getMousePoint();
    gImageCutter.scale ( pt.x, pt.y, v.z / 120.0 );
}

void ImageCutterWindow::setSelectorCursor()
{
    HCURSOR hCur;
    hCur = LoadCursor ( NULL, IDC_CROSS );
    SetCursor ( hCur );
}

void ImageCutterWindow::moveSelctorLeft()
{
    gImageCutter.offsetSelector (
        Content::InputSystem.isKeyPressing ( DIK_LSHIFT ) ? -10 : -1, 0 );
}

void ImageCutterWindow::moveSelctorRight()
{
    gImageCutter.offsetSelector (
        Content::InputSystem.isKeyPressing ( DIK_LSHIFT ) ? 10 : 1, 0 );
}

void ImageCutterWindow::moveSelctorUp()
{
    gImageCutter.offsetSelector (
        0, Content::InputSystem.isKeyPressing ( DIK_LSHIFT ) ? -10 : -1 );
}

void ImageCutterWindow::moveSelectorDown()
{
    gImageCutter.offsetSelector (
        0, Content::InputSystem.isKeyPressing ( DIK_LSHIFT ) ? 10 : 1 );
}

void ImageCutterWindow::beginDragTape()
{

}

void ImageCutterWindow::dragTape()
{
    POINT pt = Content::InputSystem.getMousePoint();
    if ( pt.x != 0 || pt.y != 0 )
    {
        gImageCutter.dragSelcotr ( pt.x, pt.y );
    }
}

void ImageCutterWindow::beginOffsetCanvas()
{
    HCURSOR hCur;
    hCur = LoadCursor ( NULL, IDC_SIZEALL );
    SetCursor ( hCur );
}

void ImageCutterWindow::addMenu ( const char* str )
{
    mScenePanel->addMenu ( str );
}

void ImageCutterWindow::config()
{
    QString imageid = mOptionSetting.value ( gImageID ).toString();

    ui.imageID->setText ( imageid );
    gImageCutter.setImageID ( imageid.toInt() );
    QValidator *validator = new QIntValidator ( this );
    ui.imageID->setValidator ( validator );
    connect ( ui.imageID, SIGNAL ( textEdited ( const QString & ) ), this, SLOT ( onTextEdited ( const QString & ) ) );

    gLuaScript.regGlobalFun ( "setClipboardStr", setClipboardStr );
    gLuaScript.regClass<GTapeNode> ( "GTapeNode" );
    gLuaScript.regClassFunction<GTapeNode> ( "getRealX", &GTapeNode::getRealX );
    gLuaScript.regClassFunction<GTapeNode> ( "getRealY", &GTapeNode::getRealY );
    gLuaScript.regClassFunction<GTapeNode> ( "getRealW", &GTapeNode::getRealW );
    gLuaScript.regClassFunction<GTapeNode> ( "getRealH", &GTapeNode::getRealH );

    gLuaScript.regClass<ImageCutterWindow> ( "ImageCutterWindow" );
    gLuaScript.regClassFunction<ImageCutterWindow> ( "addMenu", &ImageCutterWindow::addMenu );


    if ( gLuaScript.doFile ( "config.lua" ) )
    {
        gLuaScript.callVoid ( "loadMenus", this );
    }
}

void ImageCutterWindow::onTextEdited ( const QString & s )
{
    gImageCutter.setImageID ( s.toUInt() );
    mOptionSetting.setValue ( gImageID, s );
}

void ImageCutterWindow::clearDisplay()
{
    ui.label_size->clear();
    clearSelectorInfo();
}


void ImageCutterWindow::onStateChanged ( int state )
{
    gImageCutter.onlyDisplayAlpha ( state == Qt::Checked );
}

void ImageCutterWindow::clearSelectorInfo()
{
    ui.label_name->clear();
    ui.label_pos->clear();
    ui.label_wh->clear();
}

void ImageCutterWindow::updateTextureInfo()
{
    GTapeNode* tape = gImageCutter.getSelcotr();
    if ( tape )
    {
        uString str;
        str.format ( "Scale:%4.0lf", Content::UIMgr.getRootNode()->getScaleX() );
        ui.label_name->setText ( str.c_str() );
        str.format ( "Texture W:%d	H:%d", gImageCutter.getW(), gImageCutter.getH() );
        ui.label_size->setText ( str.c_str() );
    }
}





ImageCutterWindow* ImageCutterWindow::mInstance = nullptr;


const char* ImageCutterWindow::Option = "Option";

const char* ImageCutterWindow::AppName = "ImageCutter";

