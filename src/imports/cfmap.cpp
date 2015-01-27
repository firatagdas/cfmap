#include <QtQml/qqmlextensionplugin.h>
#include <QtQml/qqml.h>
#include <CFMvc/cfmodel.h>
#include <CFMap/cfmapmodel.h>
#include <CFMap/cfmapview.h>

CFMVC_DEFINE_MODEL(CFMapModel)

QT_BEGIN_NAMESPACE

class CFMapModule : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface/1.0")
public:
    void registerTypes(const char *uri)
    {
        Q_ASSERT(QLatin1String(uri) == QLatin1String("CFMap"));

        // @uri CFMap
        qmlRegisterSingletonType<CFMapModel>(uri, 1, 0, "CFMapModel", CFMVC_MODEL(CFMapModel));
        qmlRegisterType<CFMapView>(uri, 1, 0, "CFMapView");
    }

    void initializeEngine(QQmlEngine *engine, const char *uri)
    {
        Q_UNUSED(uri);
        Q_UNUSED(engine);
    }
};

QT_END_NAMESPACE

#include "cfmap.moc"



