#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <string>
#include <vector>
#include "Event.h"
#include <QMainWindow>
#include <sstream>
#include <QListWidgetItem>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_create_demonstration_clicked();

    void on_edit_demonstration_clicked();

    void on_return_to_menu_clicked();

    void on_remove_event_clicked();

    void on_back_from_dell_event_clicked();

    void on_add_event_clicked();

    void on_back_from_add_event_clicked();

    void on_remove_demonstration_clicked();

    void on_remove_all_event_clicked();

    void on_back_from_dell_all_clicked();

    void on_ADD_event_clicked();

    void on_DELL_event_clicked();

    void on_DELL_ALL_event_clicked();

    void on_read_event_clicked();

    void on_edit_num_experement_clicked();

    void on_start_demonstration_clicked();

    void on_read_statistics_clicked();

private:
    Ui::MainWindow *ui;

    std::vector<demonstration> demonstrations;

    std::string NAME_demo;

};
#endif // MAINWINDOW_H
