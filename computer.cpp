#include "computer.h"

Computer::Computer(int id, DeviceType deviceType, QString producer, QString model, int count, double price, QImage image, ImageType imageType, QString description)
    :   Device(id, deviceType, producer, model, count, price, image, imageType)
{
    QJsonDocument qJsonDocument = QJsonDocument::fromJson(description.toUtf8());
    QJsonObject qJsonObject = qJsonDocument.object();
    m_processor = qJsonObject.value("processor").toString();
    m_ram = qJsonObject.value("ram").toString();
    m_graphicsCard = qJsonObject.value("graphics card").toString();
    m_disc = qJsonObject.value("disc").toString();
    m_powerSupply = qJsonObject.value("power supply").toString();
    m_system = qJsonObject.value("system").toString();
}

const QString Computer::processor() const
{
    return m_processor;
}

void Computer::setProcessor(QString processor)
{
    m_processor = processor;
}

const QString Computer::ram() const
{
    return m_ram;
}

void Computer::setRam(const QString ram)
{
    m_ram = ram;
}

const QString Computer::graphicsCard() const
{
    return m_graphicsCard;
}

void Computer::setGraphicsCard(QString graphicsCard)
{
    m_graphicsCard = graphicsCard;
}

const QString Computer::disc() const
{
    return m_disc;
}

void Computer::setDisc(QString disc)
{
    m_disc = disc;
}

const QString Computer::powerSupply() const
{
    return m_powerSupply;
}

void Computer::setPowerSupply(QString powerSupply)
{
    m_powerSupply = powerSupply;
}

QString Computer::description()
{
    return QString("processor: %1\nram: %2\ngraphics card: %3\ndisc: %4\npower supply: %5")
            .arg(m_processor, m_ram, m_graphicsCard, m_disc, m_powerSupply);
}
