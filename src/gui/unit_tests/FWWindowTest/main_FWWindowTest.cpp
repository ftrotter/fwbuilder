#include "FWWindowTest.h"
#include "FWWindow.h"
#include "FWBSettings.h"
#include "common/commoninit.h"
#include <iostream>
#include "fwbuilder/Resources.h"

int fwbdebug = 0;
FWWindow *mw = NULL;
FWBSettings *st = NULL;
char** args;
QApplication *app = NULL;

using namespace libfwbuilder;
using namespace std;

int main( int argc, char** argv)
{
    app = new QApplication(argc, argv, 0);
    app->setOrganizationName(QLatin1String("NetCitadel"));
    app->setApplicationName(QLatin1String("Firewall Builder"));
    st = new FWBSettings();
    st->init();
    init(argv);

    string full_res_path = respath + FS_SEPARATOR + "resources.xml";

    try
    {
        new Resources(full_res_path);
    } catch (FWException &e)
    {
        cerr << "Can not read resource file from " << full_res_path << endl;
    }
    FWWindowTest tst;
    QTest::qExec(&tst);
}
