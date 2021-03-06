#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QMainWindow>
#include <QSettings>
#include <QDate>
#include <tuple>
#include <QMessageBox>
using namespace std;

namespace Ui {
class SettingsManager;
}

class SettingsManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit SettingsManager(QWidget *parent = nullptr);
    ~SettingsManager();
    void setConf();
    void loadConf();
	void saveSettings(const QString &key, const QVariant &value, const QString &group);
	QVariant loadSettings(const QString &key, const QString &group, const QVariant &defaultValue);
private slots:


    void on_saveButton_clicked();

    void on_loadButton_clicked();

    void on_cancelButton_clicked();

    void on_applyButton_clicked();

    void on_checkBox_toggled(bool checked);

private:
    Ui::SettingsManager *ui;
    QString defDbName = "aklatan.db";
    double defDamagePenalty = 150;
    double defLatePenalty = 150;
    int defDaysDue = 3;
    void saveConf();



};

extern QString dbName;
extern double damagePenalty;
extern double latePenalty;
extern QString lpenalty;
extern QString dpenalty;
extern QDate today;
extern QDate dueDate;
extern int daysDue;

#endif // SETTINGSMANAGER_H
