class Segment;

#ifndef SEGMENT_H
#define SEGMENT_H

#include "event.h"
#include "mapstate.h"
#include "note.h"

#include <QList>

class Segment
{
public:

    friend class NoteMap;
    friend class MapState;

    Segment();

    void clear();

    int getSegmentDiv() const;
    void setSegmentDiv(int div);
    void setSegmentDivChange(int delta);
    void setSegmentDivMultiply(int times);
    void setSegmentDivDivide(int times);

    void appendNote(const Note& note);
    void appendEvent(const Event& event);

    void addNote(const Note& note);
    void addEvent(const Event& event);

    void setBeginState(const MapState& state);
    const MapState& getBeginState() const;
    MapState getNoteBeginState() const;

    MapState getEndState() const;

    void getNoteEventInfo(QList<NoteInfo>& noteList, QList<EventInfo>& eventList, const MapState& endState=MapState());

protected:

    int segmentDiv;

    QList<Note> notes;
    QList<Event> events;

    MapState beginState;

    int incStateNoteNum(MapState* state, int deltaNum=1) const;

};

#endif // SEGMENT_H