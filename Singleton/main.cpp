#include <QCoreApplication>
#include <QObject>

template <class T>
class Singleton {
public:
    static T& instance() {
        static T instance;
        return instance;
    }

private:
    Singleton() {}
    Singleton(const Singleton &) = delete;
    Singleton& operator=(const Singleton &) = delete;
};


class Volume/* : public QObject*/ {
//    Q_OBJECT ------------------------ needs to be in .h file since moc files are generated for .h
private:
    explicit Volume(){}
//signals:
//    void changed(int volume);
public slots:
    int get() const {return  m_volume;}
    void set(int volume) {m_volume = volume;}
private:
    int m_volume;
    friend class Singleton<Volume>;
};
#define VOLUME Singleton<Volume>::instance()


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Singleton<Volume>::instance().set(100);
    VOLUME.get();

    return a.exec();
}
