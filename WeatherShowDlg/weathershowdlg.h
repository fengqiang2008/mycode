/********************************************************************
*    @file   weathershowdlg.h
*    @brief  天气数据显示界面
*    @author cenyin
*    @date   
*********************************************************************/


#ifndef WEATHERSHOWDLG_H
#define WEATHERSHOWDLG_H

#include <QtWidgets/QMainWindow>
#include "ui_weathershowdlg.h"

class WeatherShowDlg : public QMainWindow
{
	Q_OBJECT

public:
    WeatherShowDlg(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~WeatherShowDlg();

private:
	Ui::WeatherShowDlgClass ui;

	void InitTree();
	void InitTable();
	void ReadData(QString str);
	QString m_path;

private slots:
	void itemClickedfun ( QTreeWidgetItem * item, int column );
	void DirTrigger();
	void DelFile();
};

#endif // WEATHERSHOWDLG_H
