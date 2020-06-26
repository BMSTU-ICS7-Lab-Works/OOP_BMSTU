#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task_manager.h"
#include "error_handler.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    request req;
    req.t = INIT;
    task_manager(req);
}

MainWindow::~MainWindow()
{
    delete ui;
}

errors draw_action(Ui::MainWindow* ui)
{
    draw dr;

    dr.gV = ui->graphicsView;
    dr.h = ui->graphicsView->height();
    dr.w = ui->graphicsView->width();

    request req;
    req.t = DRAW;
    req.dr = dr;

    errors err = (errors) task_manager(req);
    return err;
}

errors transform_and_show(request req, Ui::MainWindow* ui)
{
    errors err = (errors) task_manager(req);
    if (err)
        return err;
    else
        err = draw_action(ui);

    return err;
}

int read_move_fields(move &mo, Ui::MainWindow* ui)
{
    mo.dx = ui->lineEdit_MoveX->text().toFloat();
    mo.dy = ui->lineEdit_MoveY->text().toFloat();
    mo.dz = ui->lineEdit_MoveZ->text().toFloat();
    return NONE;
}

void MainWindow::on_button_Move_clicked()
{
    request req;
    req.t = MOVE;

    struct move mo_tmp;

    read_move_fields(mo_tmp, ui);

    req.mo = mo_tmp;
    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}

int read_scale_fields(scale &sc, Ui::MainWindow* ui)
{
    sc.kx = ui->lineEdit_ScaleX->text().toFloat();
    sc.ky = ui->lineEdit_ScaleY->text().toFloat();
    sc.kz = ui->lineEdit_ScaleZ->text().toFloat();
    return NONE;
}

void MainWindow::on_button_Scale_clicked()
{
    request req;
    req.t = SCALE;

    struct scale sc_tmp;

    read_scale_fields(sc_tmp, ui);

    req.sc = sc_tmp;

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}

int read_turn_fields(turn &tu, Ui::MainWindow* ui)
{
    tu.ox = ui->lineEdit_TurnX->text().toFloat();
    tu.oy = ui->lineEdit_TurnY->text().toFloat();
    tu.oz = ui->lineEdit_TurnZ->text().toFloat();

    tu.cx = ui->lineEdit_CX->text().toFloat();
    tu.cy = ui->lineEdit_CY->text().toFloat();
    tu.cz = ui->lineEdit_CZ->text().toFloat();
    return NONE;
}

void MainWindow::on_button_Turn_clicked()
{
    request req;
    req.t = TURN;

    struct turn tu_tmp;

    read_turn_fields(tu_tmp, ui);

    req.tu = tu_tmp;

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}

void MainWindow::on_UploadButton_clicked()
{
    request req;
    req.t = LOAD_FILE;
    req.load_f.filename = ui->Filename->text().toStdString().c_str();

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}
