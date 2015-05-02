#ifndef IMAGEPACKER_H
#define IMAGEPACKER_H

#include <QtWidgets/QMainWindow>
#include "ui_imagepacker.h"
class ScenePanel;
class IPTexture;
class ImageCutterWindow : public QMainWindow, public CXCallBack
{
public:
    static const char* AppName;
    static const char* Option;
    Q_OBJECT

public:
    ImageCutterWindow ( QWidget *parent = 0 );
    ~ImageCutterWindow();

    virtual void onCallBack ( const CXDelegate& d, CXEventArgs* e );
protected:
    void loadProject ( const char* name );
    void createMenus();
    void createConfigPanel();
    void createScenePanel();
    void createRecentFileMenu();
    void createOtherMenus();

    virtual void timerEvent ( QTimerEvent * );
    bool event ( QEvent * e );
	void addMenu ( const char* str );
	void config();
	void clearDisplay();
	void clearSelectorInfo();
	void updateTextureInfo();
private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    bool openRecentFile( );
	void onTextEdited(const QString & s);
	void onStateChanged(int);
private:
    void onClickedNode ( GUINode* node );
    void updateRecentFileActions();
    QString strippedName ( const QString &fullFileName );
	void setCurrentFile ( const char* fileName,bool remove=false );
    void clear();
	void updateSelectorInfo();

    virtual void closeEvent ( QCloseEvent * );

    static void beginOffsetCanvas();
    static void offsetCanvas();
    static void beginSelect();
    static void beginDragTape();
    static void dragTape();
    static void setSelectArea();
    static void scaleCanvas();
    static void setSelectorCursor();
    static void moveSelctorLeft();
    static void moveSelctorRight();
    static void moveSelctorUp();
    static void moveSelectorDown();
public:
    static ImageCutterWindow* mInstance;
private:

    QSettings mOptionSetting;


    enum { MaxRecentFiles = 20 };
    QAction *recentFileActs[MaxRecentFiles];
    QAction *separatorAct;

    QString mCurFile;


    QList<QAction*> mRecentFileActions;

    QMenu *fileMenu;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *saveAsAct;

    Ui::ImagePackerClass ui;

    ScenePanel* mScenePanel;


    int mIdleTimeID;
};
#endif // IMAGEPACKER_H
