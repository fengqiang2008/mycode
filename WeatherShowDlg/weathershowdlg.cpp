#include "weathershowdlg.h"
#include <QTextStream>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>

//配置文件名
const QString TXTPATH = "wpath.ini";

WeatherShowDlg::WeatherShowDlg(QWidget *parent, Qt::WindowFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	QFile sf(TXTPATH);//获取天气txt文件夹的绝对路径
	if (sf.open(QIODevice::ReadOnly))
	{
		QTextStream outs(&sf);
		m_path = outs.readLine();
	}
	sf.close();
	QDir dir(m_path);
	if (!dir.exists())
	{
		QMessageBox box(this);
		box.setText("the path error");
		box.exec();
	}

	InitTree();
	InitTable();

	connect(ui.treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(itemClickedfun(QTreeWidgetItem*,int)));
	connect(ui.actionSelectDir,SIGNAL(triggered()),this,SLOT(DirTrigger()));
	
	ui.treeWidget->setContextMenuPolicy(Qt::ActionsContextMenu);  
	QFont font;
    font.setPixelSize(50);
	QAction *delFile = new QAction("删除文件",this);
	delFile->setFont(font);
	ui.treeWidget->addAction(delFile);
	connect(delFile,SIGNAL(triggered()),this,SLOT(DelFile()));

	setWindowState(Qt::WindowMaximized);
    setWindowTitle(tr("天气预报文件阅读器"));

}

WeatherShowDlg::~WeatherShowDlg()
{

}

//删除天气txt文件及目录
void WeatherShowDlg::DelFile()
{
	if (ui.treeWidget->currentItem()->parent() != NULL)
	{
		return;
	}

	QString str = ui.treeWidget->currentItem()->text(0);
	QMessageBox msgBox(this);
	msgBox.setText("确定删除" + str + "内的气象数据？");

	msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
	msgBox.setDefaultButton(QMessageBox::No);
	int ret = msgBox.exec();

	if (ret == QMessageBox::Yes)
	{
		QDir dir;
		dir.setPath(m_path + "//" + str);
		if (dir.exists())//
		{
			QFileInfoList list = dir.entryInfoList();
			QDir *temp = new QDir();
			for (int i =0 ;i<list.size();i++)
			{
				temp->remove(list.at(i).absoluteFilePath());
			}
			temp->rmdir(m_path + "//" + str);
			delete temp;
		}
		ui.treeWidget->clear();
		InitTree();
	}
}

//气象数据TXT文件夹 目录设置
void WeatherShowDlg::DirTrigger()
{
	m_path = QFileDialog::getExistingDirectory();
	InitTree();
	QFile sf(TXTPATH);
	if (sf.open(QIODevice::WriteOnly))
	{
		QTextStream outs(&sf);
		outs<<m_path;
	}
	sf.close();
}

//文件点选显示
void WeatherShowDlg::itemClickedfun( QTreeWidgetItem * item, int /*column*/ )
{
	if (item->parent() == NULL)
	{
		return;
	}
	QString str = m_path +="//";
	str += item->parent()->text(0);
	str += "//";
	str += item->text(0);
	ReadData(str);
	ui.groupBox->setTitle(item->text(0));

}
//刷新文件tree
void WeatherShowDlg::InitTree()
{
	ui.treeWidget->clear();
	QDir dir(m_path);

	QStringList timedir = dir.entryList(QDir::Dirs|QDir::NoDotAndDotDot);
	foreach(QString timestr ,timedir)
	{
		QTreeWidgetItem *node = new QTreeWidgetItem(0);
		node->setText(0,timestr);
		ui.treeWidget->insertTopLevelItem(0,node);

		dir.setPath(m_path + "//" + timestr);
		QStringList list = dir.entryList(QDir::Files);
		foreach(QString str,list)
		{
			QTreeWidgetItem *filenode = new QTreeWidgetItem(0);
			filenode->setText(0,str);
			node->addChild(filenode);
		}
	}
	if (ui.treeWidget->topLevelItem(0))
	{
		ui.treeWidget->topLevelItem(0)->setExpanded(true);
	}
	
}

//初始化table
void WeatherShowDlg::InitTable()
{
	QStringList wheaders;
	wheaders<<"时间"<<"总辐射"<<"散射辐射"<<"水平直接辐射"<<"平均风速"
		<<"平均风向"<<"温度"<<"相对湿度"<<"气压"<<"总云量";
	ui.tableWidget->setColumnCount(wheaders.size());
	ui.tableWidget->setHorizontalHeaderLabels(wheaders);
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置只读
}

//读取文件 更新数据
void WeatherShowDlg::ReadData(QString str)
{
	QFile file(str);
	if (file.open(QIODevice::ReadOnly))
	{
		QTextStream instream(&file);
		ui.tableWidget->clearContents();
		ui.tableWidget->setRowCount(0);
		QString line;
		QStringList list;
		QStringList data;
		do 
		{
			data.clear();
			line = instream.readLine();
			list = line.split(" ");

			foreach(QString s ,list)
			{
				if (s != "")
				{
					data.append(s);
				}
			}

			ui.tableWidget->insertRow(0);
			int index = 0;
			foreach(QString s ,data)
			{
				ui.tableWidget->setItem(0,index++,new QTableWidgetItem(s));
			}
		} while (!instream.atEnd());
	}

	file.close();
	ui.tableWidget->sortItems(0,Qt::AscendingOrder);

}
