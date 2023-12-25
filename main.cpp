#include <QApplication>
#include <QWidget>
#include <QWindow>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPlainTextEdit>
#include <QWebEngineView>
#include <QTextItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto w = new QWidget;
    w->setObjectName("MainWidget");
    w->resize(1024, 768);

    auto* gridBox = new QGridLayout(w);

    auto* hBox = new QHBoxLayout;
    gridBox->addLayout(hBox, 0, 0);

    auto* sourceEdit = new QPlainTextEdit;
    sourceEdit->setWindowTitle("HTML editor");
    auto* webView = new QWebEngineView;
    webView->setWindowTitle("WebView");
    hBox->addWidget(sourceEdit, 1);
    hBox->addWidget(webView, 1);

    QObject::connect(sourceEdit, &QPlainTextEdit::textChanged, [&sourceEdit, &webView](){
        QString textChanged = sourceEdit->toPlainText();
        webView->setHtml(textChanged);
        webView->update();
    });
    w->show();
    return a.exec();
}
