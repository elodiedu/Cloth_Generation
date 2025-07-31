#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ExportPlugin.h"
#include <QFileDialog>
#include <QDir>
#include <QPixmap>
#include <QProgressDialog>
#include <QMessageBox>
#include <QVBoxLayout>
MainWindow::MainWindow(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->WaitDialog->setVisible(false);
    connect(ui->comboBox,
        static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
        this,
        &MainWindow::change_type);
    connect(ui->btnSelectImage,              // or ui->btnSelectImage
        &QPushButton::clicked,
        this,
        &MainWindow::on_btnSelectImage_clicked);
    connect(ui->pushButton,              // or ui->btnSelectImage
        &QPushButton::clicked,
        this,
        &MainWindow::on_pushButton_clicked);
    connect(ui->DeleteButton,              // or ui->btnSelectImage
        &QPushButton::clicked,
        this,
        &MainWindow::on_DeleteButton_clicked);

    connect(ui->helpButton, &QPushButton::clicked,
        this, &MainWindow::on_helpButton_clicked);
    Qt::WindowFlags flags = windowFlags();
    flags &= ~Qt::WindowContextHelpButtonHint;
    setWindowFlags(flags
        | Qt::Dialog
        | Qt::WindowStaysOnTopHint
    );



    // (Optional) set the button’s text or other properties:

  // <-- this is the show() you need
   
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    int p1  = ui->horizontalScrollBar_3->value();
    int p2  = ui->horizontalScrollBar_2->value();
    int p3  = ui->horizontalScrollBar->value();
    int idx = ui->comboBox->currentIndex();
    ui->pushButton->setEnabled(false);

    ui->WaitDialog->setText(tr("Cloth Generating. Please Wait"));
    ui->WaitDialog->setVisible(true);
    QApplication::processEvents();  // 让 UI 先刷新状态标签
    // 2) 立刻 processEvents()，让对话框先绘制出来
    QApplication::processEvents();

    ::CreatePattern_Test(p1, p2, p3, idx);
          // this closes the QDialog with “Accepted”
    ui->WaitDialog->setVisible(false);
    ui->pushButton->setEnabled(true);
    QMessageBox::information(this, "Cloth Creation Complete", tr("Your pattern has been created successfully."));
}



void MainWindow::change_type(int idx)
{
    // This function can be used to change the type of the pattern based on the index
    // For example, you can set a different pattern type based on the index value
    // This is just a placeholder for your logic
    if (idx == 0) {
        ui->page_1->setCurrentIndex(1);
        ui->page_5->setCurrentIndex(1);
    }
    else if (idx == 1) {
        ui->page_1->setCurrentIndex(1);
        ui->page_5->setCurrentIndex(1);
    }
    else if (idx == 2) {
        ui->page_1->setCurrentIndex(1);
        ui->page_5->setCurrentIndex(0);
    }
    else if (idx == 3) {
        ui->page_1->setCurrentIndex(0);
        ui->page_5->setCurrentIndex(1);
    }
  
}
void MainWindow::on_btnSelectImage_clicked() {
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Open Image"),
        QDir::homePath(),
        tr("Images (*.png *.jpg *.jpeg *.bmp *.gif);;All Files (*)")
    );
    if (!fileName.isEmpty()) {
        QPixmap pix(fileName);
        ui->Selected_Image->setPixmap(pix.scaled(
            ui->Selected_Image->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        ));
    }
    else {
        ui->Selected_Image->setText(tr("No image selected"));
    }
}
void MainWindow::on_DeleteButton_clicked() {
    int idx = ui->comboBox->currentIndex();
    ::Delete_Clothes(idx);

}

void MainWindow::on_helpButton_clicked()
{
    // 1) 创建一个新的 QDialog 作为弹窗
    QDialog* helpDlg = new QDialog(this);

    // 2) 让它在屏幕前端弹出（始终保持在最前面）
    helpDlg->setWindowFlags(helpDlg->windowFlags()
        | Qt::Dialog
        | Qt::WindowStaysOnTopHint);

    // 3) 给对话框设置一个合适的标题
    helpDlg->setWindowTitle(tr("Help Images"));

    // 4) 创建一个布局，用来放置多个 QLabel
    QVBoxLayout* mainLayout = new QVBoxLayout(helpDlg);
   
    // 假设你的图片路径是 "./help_image1.png"
    QPixmap pix(":/help/tech_pack.png");
    if (pix.isNull()) {
        // pop up an error so you know where Qt looked
        QMessageBox::warning(this,
            tr("Cannot Load Image"),
            tr("Failed to load '%1'"));
        delete helpDlg;
        return;
    }

    QLabel* imgLabel = new QLabel(helpDlg);
    imgLabel->setPixmap(pix.scaled(800, 800, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    imgLabel->setAlignment(Qt::AlignCenter);

    mainLayout->addWidget(imgLabel);
    helpDlg->setLayout(mainLayout);
    helpDlg->resize(800, 800); // 根据实际内容自定义大小
    helpDlg->show();           // 非模态弹出，也会置顶
}