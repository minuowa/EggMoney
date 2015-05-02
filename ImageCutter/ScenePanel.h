#ifndef SCENEPANEL_H
#define SCENEPANEL_H

#include <QWidget>
#include "ui_ScenePanel.h"

class ScenePanel : public QWidget
{
    Q_OBJECT

public:
    ScenePanel ( QWidget *parent = 0 );
    ~ScenePanel();
	void loadLua();
	void addMenu ( const char* str );
public:
	void copyXYWH();
	void copyWH();
	void copyButtonUpPos();
	void copyButtonUpHoverPos();
	void copyButtonDownPos();
	void copyButtonEnablePos();
	void copyRadioButtonUpPos();
	void copyRadioButtonDownPos();
	void copyNinePatchInner();
	void copyNinePatchOutter();
public slots:
	void onCopy();
signals:
	void changed ( const QMimeData *mimeData = 0 );
protected:
	void dragEnterEvent ( QDragEnterEvent *event );
	void dragMoveEvent ( QDragMoveEvent *event );
	void dragLeaveEvent ( QDragLeaveEvent *event );
	void dropEvent ( QDropEvent *event );
private:
    Ui::ScenePanel ui;
    virtual void resizeEvent ( QResizeEvent * );
    bool event ( QEvent *event );

    QMenu* mMainMenu;
};

#endif // SCENEPANEL_H
