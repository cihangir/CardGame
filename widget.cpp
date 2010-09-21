#include "widget.h"
#include "ui_widget.h"

#define TESTT
#define TEST_CONST
#undef TEST_CONST

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->gridLayout->setSpacing(0);

/*
    QString str = "Game Over!";
    str.append('\n');
    str.append("First Team");
    str += '\t';
    str += '\t';

    str.append("Second Team");
    str += '\n';
    str.append("cihangir");
    str += '\n';
    str.append("cihangir");
    str += '\n';
    str.append("cihangir");
    str += '\n';
    str.append("cihangir");

    ui->resultlabel->setText(str);
*/
    currentPlayerIndex = 0;

    mapper = new QSignalMapper(this);
    connect(mapper, SIGNAL(mapped(QObject *)), this, SLOT(cardClicked(QObject *)));

    this->setWindowTitle("Card Game");
    centerMyWindow();
    ui->southHand->setCursor(Qt::UpArrowCursor);

    /* set layouts */
    //grid = new QGridLayout(ui->table);
    //ui->table->setLayout(grid);

/*
    QFrame *frame = new QFrame;
    frame->setMinimumHeight(75);
    grid->addWidget(frame, 0, 1);
    frame = new QFrame;
    frame->setMinimumHeight(75);
    grid->addWidget(frame, 1, 1);
    frame = new QFrame;
    frame->setMinimumHeight(75);
    grid->addWidget(frame, 2, 1);

    frame = new QFrame;
    frame->setMinimumWidth(75);
    grid->addWidget(frame, 1, 0);
    frame = new QFrame;
    frame->setMinimumWidth(75);
    grid->addWidget(frame, 1, 1);
    frame = new QFrame;
    frame->setMinimumWidth(75);
    grid->addWidget(frame, 1, 2);
*/

    // ui->table->setEnabled(false); // disable table so that no one can click on it.

    hbox = new QHBoxLayout(ui->southHand);
    hbox->setAlignment(Qt::AlignCenter);
    hbox->setContentsMargins(200, 0, 200, 0);
    ui->southHand->setLayout(hbox);
    hbox = new QHBoxLayout(ui->northHand);
    hbox->setAlignment(Qt::AlignCenter);
    ui->northHand->setLayout(hbox);

    vbox = new QVBoxLayout(ui->eastHand);
    vbox->setAlignment(Qt::AlignCenter);
    ui->eastHand->setLayout(vbox);
    vbox = new QVBoxLayout(ui->westHand);
    vbox->setAlignment(Qt::AlignCenter);
    ui->westHand->setLayout(vbox);

    modifiedstart();

#ifdef TEST_CONST
    g.createCards();
    players = g.getPlayers();
    g.distributeCards(players[0], 4);
    QList<Card *> playersHand = players[0].getHand();
    QWidget *wid = (QWidget *) playersHand.at(0)->buttonPtr;
    ui->southHand->layout()->addWidget(wid);
#endif

    // start();

//    g.createCards();
//    g.dummyStart();
//    createUi();
    
#if 0
    Card *c = g.getCards().first();
    QToolButton *tb = g.createButton(c);

    layout = new QGridLayout;
    ui->table->setLayout(layout);

    QPushButton *button, *button2, *button3, *button4;
    button = new QPushButton("New Button");
    button2 = new QPushButton("Click");
    button3 = new QPushButton("Button 3");
    button4 = new QPushButton("Button 4");

    layout->addWidget(tb, 2, 1);
    layout->addWidget(button2, 1, 2);
    layout->addWidget(button3, 1, 0);
    layout->addWidget(button4, 0, 1);
#endif
}

Widget::~Widget()
{
    delete ui;
    delete mapper;
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Widget::centerMyWindow() {
    QDesktopWidget *desktop = QApplication::desktop();
    int screenWidth, width;
    int screenHeight, height;
    int x, y;
    QSize windowSize;

    screenWidth = desktop->width(); // get width of screen
    screenHeight = desktop->height(); // get height of screen

    windowSize = size(); // size of our application window
    width = windowSize.width();
    height = windowSize.height();

    // little computations
    x = (screenWidth - width) / 2;
    y = (screenHeight - height) / 2;

    // move window to desired coordinates
    move ( x, y );
}

/* create card game UI */
#if 0
void Widget::createUi()
{
    // QLayout *frameLayout = ui->southHand->layout();
    Person *players = g.getPlayers();
    QList<Card *> playersHand;

    QHBoxLayout *hb = new QHBoxLayout;
    ui->northHand->setLayout(hb);
    hb->setContentsMargins(100, 0, 100, 0);

    for (int i = 0; i < g.getNumberOfOnlinePlayer(); i++) {
        playersHand = players[i].getHand();
        for (int j = 0; j < players[i].getHand().size(); j++) {
            QToolButton *but = g.createButton(playersHand.at(j));

            switch (i) {
            case 0:
                ui->southHand->layout()->addWidget(but);
                break;
            case 1:
                ui->northHand->layout()->addWidget(but);
                break;
            case 2:
                ui->westHand->layout()->addWidget(but);
                break;
            case 3:
                ui->eastHand->layout()->addWidget(but);
                break;
            }
        }
    }
}
#endif

void Widget::start()
{
    // test value
    maxpoint = 100;

    QFrame *frame;
    QLayout *currentLayout;
    QHBoxLayout *hbox;
    QVBoxLayout *vbox;
    QList<Card *> playersHand;
    QString pos;
    bool myself = false;
    Person *currentPlayer;

    g.createCards();
    players = g.getPlayers();

    for (int i = 0; i < 4; i++) {
        Card *c = g.getCards().takeFirst();
        g.appendToPlayedCards(c);
    }

    for (int i = 0; i < 4; i++) {
        g.distributeCards(players[i], 4);
    }

    for (int i = 0; i < 4; i++) {
        currentPlayer = &players[i];
        playersHand = currentPlayer->getHand();

        switch (i) {
        case 0:
            frame = ui->southHand;
            hbox = new QHBoxLayout;
            currentLayout = hbox;
            hbox->setContentsMargins(200, 0, 200, 0);
            frame->setLayout(hbox);
            myself = true;
            break;
        case 1:
            frame = ui->eastHand;
            vbox = new QVBoxLayout;
            vbox->setAlignment(Qt::AlignCenter);
            currentLayout = vbox;
            frame->setLayout(vbox);
            myself = false;
            pos = 'v';
            break;
        case 2:
            frame = ui->northHand;
            hbox = new QHBoxLayout;
            hbox->setAlignment(Qt::AlignCenter);
            currentLayout = hbox;
            frame->setLayout(hbox);
            hbox->setContentsMargins(11, 0, 11, 0);
            myself = false;
            pos = 'h';
            break;
        case 3:
            frame = ui->westHand;
            vbox = new QVBoxLayout;
            vbox->setAlignment(Qt::AlignCenter);
            currentLayout = vbox;
            frame->setLayout(vbox);
            myself = false;
            pos = 'v';
            break;
        }

        for (int j = 0; j < currentPlayer->getHand().size(); j++) {
            if (myself) {
                // playersHand.at(j)->getButton() olmayacak
                // but = (QWidget *) playersHand.at(j)->buttonPtr;
                //playersHand.at(j)->getButton();
                // QWidget *voidButt = (QWidget *) playersHand.at(j)->buttonPtr;
                // qDebug() << voidButt->styleSheet() << voidButt->geometry() << voidButt;
                // but->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum));
                // ui->southHand->layout()->addWidget(voidButt);
                // voidButt->show();

                // players[0].getHand().at(0)->getButton();
                showCardOnTable(players[0].getHand().at(0), 1);

            } else {
#if 0
                but = new QToolButton;
                but->setStyleSheet(QString("border-image: url(./graphics/back/4%1.png);").arg(pos));
                but->setMinimumSize(75, 75);
                but->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum));
                currentLayout->addWidget(but);
#endif
                QList<Card *> bar = players[2].getHand();
                // currentLayout->addWidget(static_cast<QWidget *>(bar.at(3)->buttonPtr));
                qDebug() << bar.at(0)->buttonPtr << (QWidget *) bar.at(0)->buttonPtr;
                // bar.at(0)->getButton();
                qDebug() << bar.at(0)->buttonPtr << (QWidget *) bar.at(0)->buttonPtr;
                qDebug() << bar.at(0)->buttonPtr << (QWidget *) bar.at(0)->buttonPtr;
                // QWidget *debugvatGet = bar.at(0)->getButton();
                //debugvar->setParent(ui->table);
                grid->addWidget(bar.at(0)->getButton(), 1, 2);
                break;
            }
        }
    }

 /*
    Card *cd = players[0].getHand().at(3);
    QWidget *test = ui->southHand->layout()->itemAt(2)->widget();
    ui->southHand->layout()->removeWidget(test);
    test->hide();
*/

    currentPlayer = &players[0];

    int playerIndex = 0;
    bool play = true;

    int counter = 0;
    while (play) {
        /* El bittiyse kart dagit */ 
        if (currentPlayer->getNumberOfCards() == 0) {
            for (int i = 0; i < 4; i++) {
                playerIndex = (playerIndex + 1) % 4; // Next player
                currentPlayer = &players[playerIndex];
                g.distributeCards(*currentPlayer, 4);
            }
        }

        if (playerIndex == 0)
            currentLayout = ui->southHand->layout();

        Card *lastcard = g.lastPlayedCard();
        Card *c = currentPlayer->play(lastcard);
        g.appendToPlayedCards(c);
        showCardOnTable(c, playerIndex);

/*
        if (currentPlayer == &players[0]) {
            QWidget *w = (QWidget *) c->buttonPtr;
            QLayout *lay = ui->southHand->layout();
            int index = lay->indexOf(w);
            lay->removeWidget(w);
            w->hide();
        }
*/

        if (g.pisti(currentPlayer)) {
            QList<Card *> &l = g.getPlayedCards();

            for (int i = 0; i < l.size(); i++) {
                QWidget *widget = (QWidget *) l.at(i)->buttonPtr;
                grid->removeWidget(widget);
                widget->hide();
            }
            
            currentPlayer->collectCards(l);
        }

        playerIndex = (playerIndex + 1) % 4;
        currentPlayer = &players[playerIndex];

        if (g.getCards().size() == 0 && currentPlayer->getNumberOfCards() == 0)
            play = false;

        counter++;
        if(counter == 42)
            qDebug() <<  "42 ";
    }

    QList<Card *> &cardsOnTable = g.getPlayedCards();
    for (int i = 0; i < cardsOnTable.size(); i++) {
        QWidget *widget = (QWidget *) cardsOnTable.at(i)->buttonPtr;
        grid->removeWidget(widget);
        widget->hide();
    }
    g.getlastWinner()->collectCards(cardsOnTable);

#ifdef TEST
    // test begin
    QWidget *tmpwidget = ui->southHand->layout()->itemAt(0)->widget();
    ui->southHand->layout()->removeWidget(tmpwidget);
    tmpwidget->hide();
    // test end
#endif

}

void Widget::showCardOnTable(Card *c, int position)
{
    QFrame *frame;
    QWidget *button;
    int row, column, parentWidth, width, parentHeight, height;
    int x, y;

    switch (position) {
    case 0: // south
        row = 3;
        column = 2;
        frame = ui->tableSouth;
        break;
    case 1: // east
        row = 2;
        column = 3;
        frame = ui->tableEast;
        break;
    case 2: // north
        row = 1;
        column = 2;
        frame = ui->tableNorth;
        break;
    case 3: // west
        row = 2;
        column = 1;
        frame = ui->tableWest;
        break;
    case 4:
        frame = ui->tableCenter;
        break;
    }

    /* c->getButton() */
    /* (QWidget *) c->buttonPtr */
    QSize parentWidgetSize = frame->size();
    QSize buttonSize;

    parentWidth = parentWidgetSize.width();
    parentHeight = parentWidgetSize.width();

    button = static_cast<QWidget *>(c->buttonPtr);
    button->setParent(frame);

    // TODO: must be dynamically resized
    button->resize(60, 70);
    buttonSize = button->size();

    width = buttonSize.width();
    height = buttonSize.height();
    qDebug() << parentWidth << parentHeight;    
    qDebug() << width << height;
    x = (parentWidth - width) / 2;
    y = (parentHeight - height) / 2;
    y -= y / 2;

    button->move(x, y);
    button->show();
}

void Widget::showCardOnFrame(Card *c, int playerindex)
{
    if (playerindex == 0) {
        ui->southHand->layout()->addWidget((QWidget *) c->buttonPtr);
    }
}

void Widget::modifiedstart()
{
    // which player to play
    // int currentPlayerIndex = 0;

    players = g.getPlayers();
    g.createCards();

    /* Yere ucu kapali dort kart at */
    for (int i = 0; i < 3; i++) {
        Card *c = g.getCards().takeFirst();
        g.appendToPlayedCards(c);
    }
    for (int i = 0; i < g.getCards().size(); i++)
        if (g.getCards().at(i)->cardNumber != 11) {
        g.appendToPlayedCards(g.getCards().takeAt(i));
        break;
    }

    QToolButton *but = new QToolButton(ui->tableCenter);
    but->setStyleSheet(QString("border-image: url(./graphics/back/3h.png)"));
    but->setMinimumSize(75, 55);
    but->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum));

    Card *card = g.getPlayedCards().last();
    // TODO: getButton()
    // card->getButton();
    (static_cast<QWidget *>(card->buttonPtr))->setParent(ui->tableCenter);

    // TODO: i < numbeerOfPlayers
    for (int i = 0 ; i < 4; i++) {
        currentPlayer = &players[i];
        g.distributeCards( *currentPlayer, 4 );
    }

    for (int i = 1 ; i <= 3; i++) {
        showPlayerHand(i);
    }
    
    currentPlayer = &players[0];
    // connect button signals to slots
    for (int i = 0; i < currentPlayer->getNumberOfCards(); i++) {
        QList<Card *> l = currentPlayer->getHand();
        connect(static_cast<QToolButton *>(l.at(i)->buttonPtr), SIGNAL(clicked()),
                mapper, SLOT(map()));
        mapper->setMapping(static_cast<QObject *>(l.at(i)->buttonPtr),
                           static_cast<QObject *>(l.at(i)));
        ui->southHand->layout()->addWidget(static_cast<QWidget *>(l.at(i)->buttonPtr));
    }
}

void Widget::cardClicked(QObject *obj)
{
    // disable my panel
    ui->southHand->setEnabled(false);

    Card *c = static_cast<Card *>(obj);
    int del = players[0].getHand().indexOf(c);
    players[0].getHand().removeAt(del);
    ui->southHand->layout()->removeWidget(static_cast<QWidget *>(c->buttonPtr));
    g.appendToPlayedCards(c);
    showCardOnTable(c, 0);

    if (g.pisti(&players[0])) {
        QList<Card *> &l = g.getPlayedCards();

        delay(150);

        // yerdeki kartlari topla
        clearPanel(ui->tableCenter);
        clearPanel(ui->tableEast);
        clearPanel(ui->tableNorth);
        clearPanel(ui->tableWest);
        clearPanel(ui->tableSouth);
        players[0].collectCards(l);
    }

    qDebug() << c->cardImageName;
    simulateOthers();
}

void Widget::simulateOthers()
{
    QWidget *currentPlayerFrame;
    QString alignment;
    currentPlayerIndex = 1;

    delay(150);

    for (int i = 1; i <= 3; i++) {
        switch (currentPlayerIndex) {
        case 1:
            currentPlayerFrame = ui->eastHand;
            alignment = "v";
            break;
        case 2:
            currentPlayerFrame = ui->northHand;
            alignment = "h";
            break;
        case 3:
            currentPlayerFrame = ui->westHand;
            alignment = "v";
        }

        currentPlayer = &players[currentPlayerIndex];
        Card *lastcard = g.lastPlayedCard();

        qDebug() << "before" << currentPlayer->getNumberOfCards();
        Card *c = currentPlayer->dummyPlay(lastcard);
        qDebug() << "after"<< currentPlayer->getNumberOfCards();
#if 0
        QLayoutItem *child;
        while ((child = currentPlayerLayout->takeAt(0)) != 0) {
            child->widget()->hide();
            delete child;
        }
#endif
        /* removes card back images */
        clearPanel(currentPlayerFrame, true);
        showPlayerHand(currentPlayerIndex, currentPlayer->getNumberOfCards());
        g.appendToPlayedCards(c);
        showCardOnTable(c, currentPlayerIndex);

        delay(150);

        if (g.pisti(currentPlayer)) {
            QList<Card *> &l = g.getPlayedCards();

            // clearPanel(grid);
            clearPanel(ui->tableCenter);
            clearPanel(ui->tableEast);
            clearPanel(ui->tableNorth);
            clearPanel(ui->tableSouth);
            clearPanel(ui->tableWest);
            currentPlayer->collectCards(l);

            delay(150);
        }

        // TODO: Oyuncu sayisi dortten az olabilir
        qDebug() << "end of tour" << currentPlayer->getNumberOfCards();
        currentPlayerIndex = (currentPlayerIndex + 1) % 4;
        qDebug() << "currentplayerindex :" << currentPlayerIndex;
        currentPlayer = &players[currentPlayerIndex];

        /* Game over */
        if (g.getCards().size() == 0 && currentPlayer->getNumberOfCards() == 0) {
            /* yerdeki son kartlari al */
            g.getlastWinner()->collectCards(g.getPlayedCards());
            statistics();
            return;
        }
    }

    currentPlayer = &players[currentPlayerIndex];
    if (currentPlayer->getNumberOfCards() == 0) {
        int tmpindex = currentPlayerIndex;
        for (int i = 0 ; i < 4; i++) {
            g.distributeCards( *currentPlayer, 4 );
            if (currentPlayerIndex != 0)
                showPlayerHand(i);
            tmpindex = (tmpindex + 1) % 4;
            currentPlayer = &players[tmpindex];
        }

        // connect button signals to slots
        currentPlayer = &players[0];
        for (int i = 0; i < currentPlayer->getNumberOfCards(); i++) {
            QList<Card *> l = currentPlayer->getHand();
            connect(static_cast<QToolButton *>(l.at(i)->buttonPtr), SIGNAL(clicked()),
                    mapper, SLOT(map()));
            mapper->setMapping(static_cast<QObject *>(l.at(i)->buttonPtr),
                               static_cast<QObject *>(l.at(i)));
            ui->southHand->layout()->addWidget(static_cast<QWidget *>(l.at(i)->buttonPtr));
        }
    }

    // Enable my panel
    ui->southHand->setEnabled(true);
}

void Widget::on_pushButton_clicked()
{
    modifiedstart();
}

inline void Widget::delay(int count, int sleep)
{
    count = 30;
    while (count--) {
        usleep(sleep);
        QApplication::processEvents();
    }
}

void Widget::clearPanel(QWidget *widget, bool dealloc)
{
    QList<QWidget *> widgets = widget->findChildren<QWidget *>();
    QWidget *child;
    while (widgets.size() > 0) {
        child = widgets.takeFirst();
        child->hide();
        if (dealloc == true)
            delete child;
    }
}

void Widget::showPlayerHand(int index, int size)
{
    QLayout *layout;
    QString alignment;

    if (size < 1) return;

    switch (index) {
    case 0:
        layout = ui->southHand->layout();
        alignment = "h";
        break;
    case 1:
        layout = ui->eastHand->layout();
        alignment = "v";
        break;
    case 2:
        layout = ui->northHand->layout();
        alignment = "h";
        break;
    case 3:
        layout = ui->westHand->layout();
        alignment = "v";
    }

    QString style;
    QToolButton *but = new QToolButton;
    style = QString("border-image: url(./graphics/back/%1%2.png)").arg(size).arg(alignment);
    but->setMinimumSize(QSize(60, 60));
    but->setStyleSheet(style);
    layout->addWidget(but);
}

void Widget::statistics()
{
    QString resultStr;
    int pistiA = 0, pistiB = 0, scoreA = 0, scoreB = 0;

    for (int i = 0; i < 4; i++) {
        currentPlayer = &players[i];
        currentPlayer->computePlayerScore();
    }
    pistiA = players[0].pistiCount + players[2].pistiCount;
    pistiB = players[1].pistiCount + players[3].pistiCount;
    scoreA = players[0].score + players[2].score;
    scoreB = players[1].score + players[3].score;

    if (players[0].getScoredCards().size() + players[2].getScoredCards().size()>
        players[1].getScoredCards().size() + players[3].getScoredCards().size())
        scoreA += 3;
    else
        scoreB += 3;

    resultStr.append('\t');
    resultStr.append("First Team");
    resultStr.append('\t');
    resultStr.append("Second Team");
    resultStr.append('\n');

    resultStr.append("Pisti:");
    resultStr.append('\t');
    resultStr.append(QString::number(pistiA));
    resultStr.append('\t');
    resultStr.append('\t');
    resultStr.append(QString::number(pistiB));
    resultStr.append('\n');

    resultStr.append("Result:");
    resultStr.append('\t');
    resultStr.append(QString::number(scoreA));
    resultStr.append('\t');
    resultStr.append('\t');
    resultStr.append(QString::number(scoreB));
    resultStr.append('\n');

    ui->resultlabel->setText(resultStr);
    ui->stackedWidget->setCurrentIndex(2);
}
