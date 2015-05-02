#include "stdafx.h"
#include "ScenePanel.h"
#include "GGameDemoHeader.h"
#include "GGame.h"
#include "ImageCutter.h"

static const char* FileFlag = "file:///";

typedef void ( ScenePanel::*CopyFun ) ();
struct CopyItem
{
    const char* mItemName;
    CopyFun mCallBack;
};

static const CopyItem gCopyItems[] =
{
    {"copyXYWH", &ScenePanel::copyXYWH,},
    {"copyWH", &ScenePanel::copyWH,},
    {"copyButtonUpHoverPos", &ScenePanel::copyButtonUpHoverPos,},
    {"copyButtonUpHoverPos", &ScenePanel::copyButtonUpHoverPos,},
    {"copyButtonDownPos", &ScenePanel::copyButtonDownPos,},
    {"copyButtonEnablePos", &ScenePanel::copyButtonEnablePos,},
    {"copyNinePatchInner", &ScenePanel::copyNinePatchInner,},
    {"copyNinePatchOutter", &ScenePanel::copyNinePatchOutter,},
};

ScenePanel::ScenePanel ( QWidget *parent )
    : QWidget ( parent )
{
    ui.setupUi ( this );
    this->setAcceptDrops ( true );

    mMainMenu = new QMenu ( this );
    //u32 cnt = dArrayCount ( gCopyItems );
    //for ( u32 i = 0; i < cnt; ++i )
    //{
    //    const CopyItem& item = gCopyItems[i];
    //    QAction* act = new QAction ( item.mItemName, this );
    //    connect ( act, SIGNAL ( triggered() ), this, SLOT ( onCopy() ) );
    //    mMainMenu->addAction ( act );
    //}
    this->setContextMenuPolicy ( Qt::ActionsContextMenu );

}

ScenePanel::~ScenePanel()
{

}
void ScenePanel::dragEnterEvent ( QDragEnterEvent *event )
{
    event->acceptProposedAction();
    emit changed ( event->mimeData() );
}
//! [dragEnterEvent() function]

//! [dragMoveEvent() function]
void ScenePanel::dragMoveEvent ( QDragMoveEvent *event )
{
    event->acceptProposedAction();
}
//! [dragMoveEvent() function]

//! [dropEvent() function part1]
void ScenePanel::dropEvent ( QDropEvent *event )
{
    const QMimeData *mimeData = event->mimeData();
    //! [dropEvent() function part1]

    //! [dropEvent() function part2]
    if ( mimeData->hasImage() )
    {
    }
    else if ( mimeData->hasHtml() )
    {
    }
    else if ( mimeData->hasText() )
    {
        QString text = mimeData->text();
		uString str= text.toLocal8Bit().data();
        CXDynaArray<uString> strFileList;
        str.split ( '\n', strFileList );

        if ( strFileList.size() == 0 )
            strFileList.push_back ( str );

for ( uString strFile: strFileList )
        {
            strFile = strFile.substr ( strlen ( FileFlag ), -1 );
            if ( dIsPath ( strFile ) )
            {
                //gImagePacker.addPath ( strFile );
            }
            else
            {
                CXFileName xfilename ( strFile );
                gImageCutter.loadTexture ( xfilename.getOrignalName() );
            }
        }

    }
    else if ( mimeData->hasUrls() )
    {
        QList<QUrl> urlList = mimeData->urls();
        QString text;
        for ( int i = 0; i < urlList.size() && i < 32; ++i )
        {
            QString url = urlList.at ( i ).path();
            CXASSERT ( url.toStdString().c_str() );
            text += url + QString ( "\n" );
        }
        {
            text = text.right ( text.length() - 1 );
            CXFileName path ( text.toStdString().c_str() );
            uString relname;
        }
    }
    else
    {
    }
    //! [dropEvent() function part2]

    //! [dropEvent() function part3]
    setBackgroundRole ( QPalette::Dark );
    event->acceptProposedAction();
}
//! [dropEvent() function part3]

//! [dragLeaveEvent() function]
void ScenePanel::dragLeaveEvent ( QDragLeaveEvent *event )
{
    event->accept();
}
void ScenePanel::resizeEvent ( QResizeEvent *szEvent )
{
    __super::resizeEvent ( szEvent );
    QSize rc = this->frameSize();
    Content::Game.resize ( rc.width(), rc.height() );
}
bool ScenePanel::event ( QEvent* event )
{
    switch ( event->type() )
    {
    case QEvent::ContextMenu:
    {
        QContextMenuEvent* menuEvent = ( QContextMenuEvent* ) event;
        CXASSERT ( mMainMenu );
        mMainMenu->exec ( menuEvent->globalPos() );
    }
    break;
    case  QEvent::WindowActivate:
    {
        if ( this->focusWidget() == this )
            Content::Game.active ( true );
    }
    break;
    case QEvent::WindowDeactivate :
    {
        Content::Game.active ( false );
    }
    break;
    }
    return __super::event ( event );
}

void ScenePanel::onCopy()
{
    QAction *action = qobject_cast<QAction *> ( sender() );
    QString text = action->text();
    GTapeNode* tape = gImageCutter.getSelcotr();
    if ( tape )
    {
        gLuaScript.callVoid ( "onCopy", text.toStdString().c_str()
                              , gImageCutter.getImageID()
                              , tape->getRealX()
                              , tape->getRealY()
                              , tape->getRealW()
                              , tape->getRealH()
                            );
    }
    //static u32 cnt = dArrayCount ( gCopyItems );
    //for ( u32 i = 0; i < cnt; ++i )
    //{
    //    const CopyItem& item = gCopyItems[i];
    //    if ( text == item.mItemName  )
    //    {
    //        ( this->*item.mCallBack ) ();
    //    }
    //}
}

void ScenePanel::copyXYWH()
{
    QClipboard *clipboard = QApplication::clipboard();
    //clipboard->setText ( mSelectNodeName.c_str() );
}

void ScenePanel::copyWH()
{

}

void ScenePanel::copyButtonUpPos()
{

}

void ScenePanel::copyButtonUpHoverPos()
{

}

void ScenePanel::copyButtonDownPos()
{

}

void ScenePanel::copyButtonEnablePos()
{

}

void ScenePanel::copyRadioButtonUpPos()
{

}

void ScenePanel::copyRadioButtonDownPos()
{

}

void ScenePanel::copyNinePatchInner()
{

}

void ScenePanel::copyNinePatchOutter()
{

}

void ScenePanel::loadLua()
{
}

void ScenePanel::addMenu ( const char* str )
{
    QAction* act = new QAction ( str, this );
    connect ( act, SIGNAL ( triggered() ), this, SLOT ( onCopy() ) );
    mMainMenu->addAction ( act );
}
