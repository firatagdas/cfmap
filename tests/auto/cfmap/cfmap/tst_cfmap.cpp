#include <QtTest/QtTest>
#include <QtCore/qstandardpaths.h>
#include <QtCore/qdir.h>
#include <QtCore/qtemporarydir.h>
#include <QtCore/qfileinfo.h>

class tst_CFMap : public QObject
{
    Q_OBJECT
public:
    tst_CFMap()

private slots:
    void initTestCase();
};

void tst_CFMap::initTestCase()
{
}

QTEST_MAIN(tst_CFMap)

#include "tst_cfmap.moc"
