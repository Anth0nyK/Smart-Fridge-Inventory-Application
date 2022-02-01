#ifndef ORDERHELPER_H
#define ORDERHELPER_H
#include <random>
#include <sstream>

#include <QObject>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <string>
#include <QDebug>

#include <iomanip>
#include <ctime>
#include <sstream>
#include <mutex>          // std::mutex


class orderHelper : public QObject
{
    Q_OBJECT
public:
    explicit orderHelper (QObject* parent = 0 ) : QObject(parent) {}


    Q_INVOKABLE QString getUUID(){
        {
        static std::random_device              rd;
        static std::mt19937                    gen(rd());
        static std::uniform_int_distribution<> dis(0, 15);
        static std::uniform_int_distribution<> dis2(8, 11);



        std::stringstream ss;
        int i;
        ss << std::hex;
        for (i = 0; i < 8; i++) {
            ss << dis(gen);
        }
        ss << "-";
        for (i = 0; i < 4; i++) {
            ss << dis(gen);
        }
        ss << "-4";
        for (i = 0; i < 3; i++) {
            ss << dis(gen);
        }
        ss << "-";
        ss << dis2(gen);
        for (i = 0; i < 3; i++) {
            ss << dis(gen);
        }
        ss << "-";
        for (i = 0; i < 12; i++) {
            ss << dis(gen);
        };

        return QString::fromStdString(ss.str());;
    }
}
};
#endif // ORDERHELPER_H
