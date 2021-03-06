#include "intervalsettings.h"

IntervalSettings::IntervalSettings(QObject *parent) :
    QObject(parent), m_duration(1000)
{
}

int IntervalSettings::duration() const
{
    return m_duration;
}

void IntervalSettings::setDuration(int duration )
{
    if ( m_duration != duration ) {
        m_duration = duration;
        emit durationChanged();
    }
}

IntervalSettings::Unit IntervalSettings::unit() const
{
    return m_unit;
}

void IntervalSettings::setUnit(IntervalSettings::Unit unit)
{
    if ( m_unit != unit ) {
        m_unit = unit;
        emit unitChanged();
    }
}

int IntervalSettings::timeoutInMilliSeconds() const
{
    int factor = 1;

    switch ( m_unit ) {
    case Hours:
        factor *= 60; // fall through
    case Minutes:
        factor *= 60; // fall through
    case Seconds:
        factor *= 1000;
        break;

    case MilliSeconds:
        break;
    }


    return m_duration * factor;
}
