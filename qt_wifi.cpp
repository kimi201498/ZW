#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    int i =0;
    int j =0;
    int t =0;


    QVBoxLayout *groupBoxLayout;
    groupBoxLayout = new QVBoxLayout;


    system("iwlist wlan1 scan >./temp ");
    system("grep -E \"SSID|Quality\" temp >./grepTemp");
    system("grep -v \"x00\" grepTemp >./temp");
    QString fileName;
    fileName = "/home/c/qt/WifiSelect/temp";
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"!";
        return;
    }
    QTextStream in(&file);
    QString line = in.readLine();
    while (i<20)
    {
        line = in.readLine();


        for(t=27;t<line.size()-1;t++)     //take off  other words
        {
            wifiName[i] +=line[t];
        }
        line = in.readLine();
        for(t=28;t<30;t++)       //take off  other words
        {
            temp[i] +=line[t];
        }
        i++;
    }

    for(i=0;i<20;i++)
    {
        qDebug()<<"temp"<<temp[i];
        qDebug()<<"name"<<wifiName[i];
    }

    for(i=0;i<19;i++)
    {
        for(j=1;j<20;j++)
        {
            if(temp[i]<temp[j])
            {
                transfer = temp[i];
                temp[i] = temp[j];
                temp[j] = transfer;


                transfer =wifiName[i];
                wifiName[i] = wifiName[j];
                wifiName[j] = transfer;
            }
        }
    }

    i =0;
    j =0;
    int k=0;

    while(i<10)
    {
        if(wifiName[j] == '\0')
        {
           // break;
            k++;
            if(k ==10)
            {
                qDebug()<<"false";
                QMessageBox messageBox;
                messageBox.setText(tr("无法搜索WLAN信号"));
                messageBox.setIcon(QMessageBox::Warning);
                messageBox.exec();
            }
        }
        else if(!(wifiName[j] =='\0'))
        {
            radioBtn[i] = new QRadioButton;
            radioBtn[i]->setText(wifiName[j]);
            groupBoxLayout->addWidget(radioBtn[i]);
            i++;
        }
        j++;
    }


/*
    QTextStream in(&file);
    QString line = in.readLine();
    while (i<10)
    {
        line = in.readLine();
        QString temp;
        for(t=27;t<line.size()-1;t++)       //take off  other words
        {
            temp +=line[t];
        }
        qDebug()<<temp;
        if(!(temp =='\0'))
        {
            radioBtn[i] = new QRadioButton;
            radioBtn[i]->setText(temp);
            groupBoxLayout->addWidget(radioBtn[i]);
            i++;
        }
    }
*/
    ui->groupBox->setLayout(groupBoxLayout);
  //  system("ping 192.168.0.223");
}


Widget::~Widget()
{
    delete ui;
}


void Widget::on_cancelBtn_clicked()
{
    this->close();
}


void Widget::on_connectBtn_clicked()
{
    if(radioBtn[0]->isChecked())
    {
        QString wifiName = radioBtn[0]->text();
        QString wifiConnect = tr("iwconfig wlan1 essid \"%1\" ").arg(wifiName);
        system(wifiConnect.toAscii());
    }
    if(radioBtn[1]->isChecked())
    {
        QString wifiName = radioBtn[1]->text();
        QString wifiConnect = tr("iwconfig wlan1 essid \"%1\" ").arg(wifiName);
        system(wifiConnect.toAscii());
    }
    if(radioBtn[2]->isChecked())
    {
        QString wifiName = radioBtn[2]->text();
        QString wifiConnect = tr("iwconfig wlan1 essid \"%1\" ").arg(wifiName);
        system(wifiConnect.toAscii());
    }
    if(radioBtn[3]->isChecked())
    {
        QString wifiName = radioBtn[3]->text();
        QString wifiConnect = tr("iwconfig wlan1 essid \"%1\" ").arg(wifiName);
        system(wifiConnect.toAscii());
    }
    if(radioBtn[4]->isChecked())
    {
        QString wifiName = radioBtn[4]->text();
        QString wifiConnect = tr("iwconfig wlan1 essid \"%1\" ").arg(wifiName);
        system(wifiConnect.toAscii());
    }
    if(radioBtn[5]->isChecked())
    {
        QString wifiName = radioBtn[5]->text();
        QString wifiConnect = tr("iwconfig wlan1 essid \"%1\" ").arg(wifiName);
        system(wifiConnect.toAscii());
    }
    if(radioBtn[6]->isChecked())
    {
        QString wifiName = radioBtn[6]->text();
        QString wifiConnect = tr("iwconfig wlan1 essid \"%1\" ").arg(wifiName);
        system(wifiConnect.toAscii());
    }
    if(radioBtn[7]->isChecked())
    {
        QString wifiName = radioBtn[7]->text();
        QString wifiConnect = tr("iwconfig wlan1 essid \"%1\" ").arg(wifiName);
        system(wifiConnect.toAscii());
    }
    if(radioBtn[8]->isChecked())
    {
        QString wifiName = radioBtn[8]->text();
        QString wifiConnect = tr("iwconfig wlan1 essid \"%1\" ").arg(wifiName);
        system(wifiConnect.toAscii());
    }
    if(radioBtn[9]->isChecked())
    {
        QString wifiName = radioBtn[9]->text();
        QString wifiConnect = tr("iwconfig wlan1 essid \"%1\" ").arg(wifiName);
        system(wifiConnect.toAscii());
    }
    QMessageBox messageBox;
    messageBox.setText(tr("连接成功！"));
    messageBox.exec();
    this->close();
}