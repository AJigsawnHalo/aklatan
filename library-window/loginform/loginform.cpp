#include "library-window/loginform/loginform.h"
#include "ui_loginform.h"
#include "common/dbmanager/dbmanager.h"
#include "common/settings/settingsmanager.h"
#include <QDebug>
LoginForm::LoginForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    this->setWindowTitle("Aklatan - Login");


}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::dbCheck()
{
    //Check for database connection
    if (!db.connOpen() == true){
        ui->labelStatus->setText("Failed to connect to Database.");

    }
    else{
        ui->labelStatus->setText("Database Connected.");
    }

}

void LoginForm::on_pushButton_clicked()
{


    //get the username and password in the line edit fields
    QString username,password;
    username = ui->line_Username->text();
    password = ui->line_Password->text();

    QSqlQuery query; //initialize the query
    query.prepare("select * from admin where username='"+username +"' and password='"+password+"'"); //get the username and password from the database

    if (query.exec()){
        int count = 0;
        while (query.next()) {
            count++;
        }

        if(count == 1){
            //open the Main Library Window if there's a matching username and password then close the Login window.
            lib.show();
            lib.loadStatus();
            this->hide();
            //db.connClose();
        }
        else if(count > 1){
            qDebug() << "Duplicate Username and Password";
            ui->labelStatus->setText("Duplicate Username and Password");
        }
        else{
            qDebug() << "Incorrect Username and Password";
            ui->labelStatus->setText("Incorrect Username and Password");
        }
    }


}
