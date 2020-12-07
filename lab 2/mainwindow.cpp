#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <string>
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->remove_event->hide();
    ui->remove_all_event->hide();
    ui->add_event->hide();
    ui->return_to_menu->hide();
    ui->enter_probality->hide();
    ui->enter_event->hide();
    ui->name_event->hide();
    ui->size_probality->hide();
    ui->ADD_event->hide();
    ui->DELL_ALL_event->hide();
    ui->DELL_event->hide();
    ui->back_from_dell_all->hide();
    ui->back_from_add_event->hide();
    ui->back_from_dell_event->hide();

      ui->label_del_all->hide();

      ui->num_experement->hide();
      ui->enter_num_experement->hide();
      ui->edit_num_experement->hide();
}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_create_demonstration_clicked()
{
    if(ui->name_demonstration->text()==""){
        QMessageBox::information(this,"Попередження","ви не увели назву демонстрації");}
    if(ui->name_demonstration->text().length()>25){
         QMessageBox::information(this,"Попередження","занадто великий текст \n уведіть текст менший 15 символів");
     } else{

       QString a=ui->name_demonstration->text();
         demonstration new_dem(a.toStdString());
            demonstrations.push_back(new_dem);

         }
         ui->name_demonstration->clear();
    }


void MainWindow::on_edit_demonstration_clicked()
{
    if(ui->name_demonstration->text()==""){
        QMessageBox::information(this,"Попередження","ви не увели назву демонстрації");}
    if(ui->name_demonstration->text().length()>25){
         QMessageBox::information(this,"Попередження","занадто великий текст \n уведіть текст менший 25 символів");
     }

     if(!(ui->name_demonstration->text()=="")&&!(ui->name_demonstration->text().length()>25))
    {
         bool t=true;
         for(int i=0;i<demonstrations.size();i++){
             if(demonstrations[i].Name_show()==ui->name_demonstration->text().toStdString()){
                 t=false;
                 break;
             }
         }
         if(t){
              QMessageBox::information(this,"Попередження","такої демонстрації немає у списку");
         }
         else if(!t){

                NAME_demo=ui->name_demonstration->text().toStdString();

                ui->remove_event->show();
                ui->remove_all_event->show();
                ui->add_event->show();
                ui->return_to_menu->show();
                ui->num_experement->show();
                ui->enter_num_experement->show();
                ui->edit_num_experement->show();


                ui->create_demonstration->hide();
                ui->edit_demonstration->hide();
                ui->remove_demonstration->hide();
                ui->start_demonstration->hide();
                ui->Enter_label->hide();
                ui->name_demonstration->hide();
                ui->read_event->hide();
         }
    }



}

void MainWindow::on_return_to_menu_clicked()
{
    ui->remove_event->hide();
    ui->remove_all_event->hide();
    ui->add_event->hide();
    ui->return_to_menu->hide();
    ui->num_experement->hide();
    ui->enter_num_experement->hide();
    ui->edit_num_experement->hide();

    ui->create_demonstration->show();
    ui->edit_demonstration->show();
    ui->remove_demonstration->show();
    ui->start_demonstration->show();
    ui->Enter_label->show();
    ui->name_demonstration->show();
    ui->read_event->show();

    NAME_demo="";
}

void MainWindow::on_remove_event_clicked()
{

    ui->remove_event->hide();
    ui->remove_all_event->hide();
    ui->add_event->hide();
    ui->return_to_menu->hide();
    ui->num_experement->hide();
    ui->enter_num_experement->hide();
    ui->edit_num_experement->hide();

    ui->DELL_event->show();
    ui->back_from_dell_event->show();
    ui->enter_event->show();
    ui->name_event->show();
}



void MainWindow::on_back_from_dell_event_clicked()
{
    ui->remove_event->show();
    ui->remove_all_event->show();
    ui->add_event->show();
    ui->return_to_menu->show();
    ui->num_experement->show();
    ui->enter_num_experement->show();
    ui->edit_num_experement->show();

    ui->DELL_event->hide();
    ui->back_from_dell_event->hide();
    ui->enter_event->hide();
    ui->name_event->hide();
}

void MainWindow::on_add_event_clicked()
{
    ui->remove_event->hide();
    ui->remove_all_event->hide();
    ui->add_event->hide();
    ui->return_to_menu->hide();
    ui->num_experement->hide();
    ui->enter_num_experement->hide();
    ui->edit_num_experement->hide();

    ui->ADD_event->show();
    ui->back_from_add_event->show();
    ui->enter_event->show();
    ui->name_event->show();
    ui->size_probality->show();
    ui->enter_probality->show();



}

void MainWindow::on_back_from_add_event_clicked()
{
    ui->remove_event->show();
    ui->remove_all_event->show();
    ui->add_event->show();
    ui->return_to_menu->show();
    ui->num_experement->show();
    ui->enter_num_experement->show();
    ui->edit_num_experement->show();

    ui->enter_event->hide();
    ui->name_event->hide();
    ui->size_probality->hide();
    ui->enter_probality->hide();
    ui->ADD_event->hide();
    ui->back_from_add_event->hide();




}

void MainWindow::on_remove_demonstration_clicked(){
if(ui->name_demonstration->text()==""){
    QMessageBox::information(this,"Попередження","ви не увели назву демонстрації");}
if(ui->name_demonstration->text().length()>25){
     QMessageBox::information(this,"Попередження","занадто великий текст \n уведіть текст менший 25 символів");
}else{
    int N =demonstrations.size();
    QString b=ui->name_demonstration->text();
    demonstration a(b.toStdString());
   for(int i=0;i<N;i++){
   if(demonstrations[i].Name_show()==a.Name_show()){
       for(int j=i;j<N-1;j++){
           demonstrations[j]=demonstrations[j+1];
       }
       demonstrations.pop_back();
    }
   }
}
 ui->name_demonstration->clear();
}



void MainWindow::on_remove_all_event_clicked()
{
    ui->remove_event->hide();
    ui->remove_all_event->hide();
    ui->add_event->hide();
    ui->return_to_menu->hide();
    ui->num_experement->hide();
    ui->enter_num_experement->hide();
    ui->edit_num_experement->hide();

    ui->DELL_ALL_event->show();
    ui->back_from_dell_all->show();
    ui->label_del_all->show();
}

void MainWindow::on_back_from_dell_all_clicked()
{
    ui->remove_event->show();
    ui->remove_all_event->show();
    ui->add_event->show();
    ui->return_to_menu->show();
    ui->num_experement->show();
    ui->enter_num_experement->show();
    ui->edit_num_experement->show();

    ui->DELL_ALL_event->hide();
    ui->back_from_dell_all->hide();
    ui->label_del_all->hide();
}

void MainWindow::on_ADD_event_clicked()
{
      if(ui->name_event->text()==""||ui->size_probality->text()==""){
           QMessageBox::information(this,"Попередження","ви не увели назву події або ймовірність");
      }
      else{


      QString name_of_event=ui->name_event->text();
      QString chance=ui->size_probality->text();
      double Chance=chance.toDouble();
      std::string Name_of_event=name_of_event.toStdString();
      Event event(Name_of_event,Chance);
      int N=demonstrations.size();
      for(int i=0;i<N;i++){
          if(demonstrations[i].Name_show()==NAME_demo){
              demonstrations[i].add_event(event);
              break;
          }
      }
      ui->name_event->clear();
      ui->size_probality->clear();

      }


}

void MainWindow::on_DELL_event_clicked()
{
      if((ui->name_event->text()=="")){
           QMessageBox::information(this,"Попередження","ви не увели назву події");
      }
      else{
    QString name_of_event=ui->enter_event->text();
    QString chance=ui->enter_probality->text();
    double Chance=chance.toDouble();
    std::string Name_of_event=name_of_event.toStdString();
    Event event(Name_of_event,Chance);
    int N=demonstrations.size();
    for(int i=0;i<N;i++){
        if(demonstrations[i].Name_show()==NAME_demo){
            demonstrations[i].remove_event(event);
            break;
        }
    }
    ui->name_event->clear();
      }
}

void MainWindow::on_DELL_ALL_event_clicked()
{


    int N=demonstrations.size();
    for(int i=0;i<N;i++){
        if(demonstrations[i].Name_show()==NAME_demo){
            demonstrations[i].remove_all_event();
            break;
        }
    }

    ui->remove_event->show();
    ui->remove_all_event->show();
    ui->add_event->show();
    ui->return_to_menu->show();

    ui->DELL_ALL_event->hide();
    ui->back_from_dell_all->hide();
    ui->label_del_all->hide();

}

void MainWindow::on_read_event_clicked()
{
    if(ui->name_demonstration->text()==""){
        QMessageBox::information(this,"Попередження","ви не увели назву демонстрації");}
    if(ui->name_demonstration->text().length()>25){
         QMessageBox::information(this,"Попередження","занадто великий текст \n уведіть текст менший 25 символів");}
    else{
    QString a;
    int N=demonstrations.size();

    for(int i=0;i<N;i++){

        if(demonstrations[i].Name_show()==ui->name_demonstration->text().toStdString()){

       std::vector<Event> b=demonstrations[i].events;
       QString event="";
            for( int j=0;j<demonstrations[i].num_events();j++){

               event=QString("Name: %1, chance - %2").arg(
                           QString::fromStdString(b[j].GetName()),
                           QString::fromStdString(std::to_string(b[j].GetChance())));
               a+=event;
               a+="\n";
            }

        }
    }
    ui->label->setText(a);
    }


}

void MainWindow::on_edit_num_experement_clicked()
{
    QString a=ui->enter_num_experement->text();
    int V=a.toInt();
    int N=demonstrations.size();
    for(int i=0;i<N;i++){
        if(demonstrations[i].Name_show()==NAME_demo){
            demonstrations[i].set_num(V);
            break;
        }
    }
    ui->enter_num_experement->clear();
}

void MainWindow::on_start_demonstration_clicked()
{
    if(ui->name_demonstration->text()==""){
        QMessageBox::information(this,"Попередження","ви не увели назву демонстрації");}
    if(ui->name_demonstration->text().length()>25){
         QMessageBox::information(this,"Попередження","занадто великий текст \n уведіть текст менший 15 символів");
     } else{
        int A;
        int N=demonstrations.size();
      std::vector<std::string> exp;
        for(int i=0;i<N;i++){

            if(demonstrations[i].Name_show()==ui->name_demonstration->text().toStdString()){
                A=i;
               demonstrations[i].start_demonstration();
             exp=demonstrations[i].getExperment();
            }
        }
       if(exp.size()){
           std::string EXP="";
           for(int i=0;i<exp.size();i++){
               EXP+=std::to_string(i+1)+" ";
               EXP+=exp[i];
               EXP+="\n";
           }
           QString e=QString("%1").arg(QString::fromStdString(EXP));
           ui->label->setText(e);
           demonstrations[A].end_demonstration();



       }
    }
}

void MainWindow::on_read_statistics_clicked()
{
    if(ui->name_event_for_statistics->text()==""||ui->name_demomstration_for_statistic_->text()==""){
        QMessageBox::information(this,"Попередження","ви не увели назву демонстрації або назву події");}
    else{
        int N=demonstrations.size();
        std::vector<Event> event;
        bool f=true;
        for(int i=0;i<N;i++){
            if(demonstrations[i].Name_show()==ui->name_demomstration_for_statistic_->text().toStdString()){
                event=demonstrations[i].events;
            f=false;
            break;
            }
        }
        if(f)
        {
             QMessageBox::information(this,"Попередження","ви не створювали цю демонстрацію");
        }
        else{
            f=true;
            Event ev;
            int num=event.size();
            for(int i=0;i<num;i++){
               if(event[i].GetName()==ui->name_event_for_statistics->text().toStdString()){
                   f=false;
                   ev=event[i];
                   break;
               }
            }
            if(f){
                 QMessageBox::information(this,"Попередження","такої події не знайдено в цій демонстрації");
            }
            else{
                std::string res ="";
                res +="назва :    "+ev.GetName()+"\n";
                res+="кількість випадінь:  "+std::to_string(ev.GetNumberOfResults())+"\n";
                res+="частота випадіння у цій демонстрації:  "+std::to_string(ev.Get_frequency());
                QString a=QString("%1").arg(QString::fromStdString(res));
                ui->label->setText(a);
            }
        }
    }
    ui->name_demomstration_for_statistic_->clear();
    ui->name_event_for_statistics->clear();
}
