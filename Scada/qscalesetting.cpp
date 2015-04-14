#include "qscalesetting.h"
#include <qstringlistmodel.h>
#include <qstringlist.h>
#include <qstandarditemmodel.h>
#include <qmessagebox.h>
#include "configure.h"
#include "addScaleData.h"

QScaleSetting::QScaleSetting(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
   
    initTableView();
}

QScaleSetting::~QScaleSetting()
{

}
                             
//private functions
//初始化TableView控件
void QScaleSetting::initTableView()
{
    ui.tableView->setSortingEnabled(true);  //设置可排序
    QStandardItemModel *head_model = new QStandardItemModel();
    head_model->setHorizontalHeaderItem(0, new QStandardItem(QString::fromLocal8Bit("标准值")));
    head_model->setHorizontalHeaderItem(1, new QStandardItem(QString::fromLocal8Bit("实际值")));
   
    Configure config("scaleSetting.ini");
    QStringList standardData = config.configureRead("standardDistance").toStringList();
    QStringList reallyData = config.configureRead("reallyDistance").toStringList();
    int standardDataSize = standardData.size();
    int reallyDataSize = reallyData.size();
    int size = qMin(standardDataSize, reallyDataSize);
    head_model->setRowCount(size);
    for(int i=0; i<size; ++i)
    {
        head_model->setItem(i,0,new QStandardItem(standardData.at(i)));
        head_model->setItem(i,1,new QStandardItem(reallyData.at(i)));
    }
    ui.tableView->setModel(head_model);
   // ui.tableView->setSelectionMode(QAbstractItemView::ContiguousSelection | QAbstractItemView::ExtendedSelection);
}

bool QScaleSetting::insertScaleRow(int row)
{
    QStandardItemModel *model = (QStandardItemModel*)ui.tableView->model();
    if(row >= model->rowCount())
        model->insertRow(model->rowCount(),QModelIndex());
    else
        model->insertRow(row,QModelIndex());
    return true;
}

//public slots functions
void QScaleSetting::on_pushButton_addData_clicked()
{
    AddScaleData scaleData;
    int ret = scaleData.exec();
    if(ret == QDialog::Accepted)
    {
        QStringList standardData =  scaleData.getStandardDistance();
        QStringList reallyData = scaleData.getReallyDistance();
        int size = qMin(standardData.size() , reallyData.size());

        QStandardItemModel *model = (QStandardItemModel*) ui.tableView->model();
        for(int i=0; i<size; ++i)
        {
            insertScaleRow(model->rowCount());
            model->setItem(model->rowCount()-1,0,new QStandardItem(standardData.at(i)));
            model->setItem(model->rowCount()-1,1,new QStandardItem(reallyData.at(i)));
        }
    }
}

// 删除所选择的行数
void QScaleSetting::on_pushButton_deleteData_clicked()
{
    QItemSelectionModel *selections = ui.tableView->selectionModel();
    QModelIndexList selected = selections->selectedIndexes();
    QMessageBox::about(this,"selected",QString::number(selected.size()));
    int ret = QMessageBox::question(this, QString::fromLocal8Bit("删除数据"), QString::fromLocal8Bit("是否删除所选择的行?"));
    if(ret == QMessageBox::No)
        return;

    int deletecount = 0;     //记录已删除数据的数量
    foreach (QModelIndex index, selected)
    {
        ui.tableView->model()->removeRow(index.row()-deletecount, QModelIndex());    //删除选择项
        ++deletecount;
    }
}

//保存数据
void QScaleSetting::on_pushButton_save_clicked()
{
    ui.tableView->sortByColumn(0,Qt::AscendingOrder);
    QStandardItemModel *model = (QStandardItemModel*)ui.tableView->model();
    
    int row = model->rowCount();
    
    QStandardItem *standardItem, *reallyItem;
    QStringList standardList, reallyList;
    QString str;
    for(int i=0; i<row; i++)
    {
        QModelIndex standardIndex = model->index(i,0,QModelIndex());
        QModelIndex reallyIndex = model->index(i,1,QModelIndex());
        QString standardData =  model->data(standardIndex, Qt::EditRole).toString();
        QString reallyData = model->data(reallyIndex, Qt::EditRole).toString();

        if(!standardData.isEmpty() && reallyData.isEmpty())
        {
            reallyData = standardData;
        }

        if(!standardData.isEmpty() && !reallyData.isEmpty())
        {
            standardList << standardData;
            reallyList << reallyData;
        }
        else
            break;
    
    }
    
    Configure config("scaleSetting.ini");
    config.configureWrite(standardList, "standardDistance");
    config.configureWrite(reallyList, "reallyDistance");
}

void QScaleSetting::on_pushButton_cancel_clicked()
{
    insertScaleRow(4);
}

//恢复默认设置
void QScaleSetting::on_pushButton_default_clicked()
{
    initTableView();  
}
