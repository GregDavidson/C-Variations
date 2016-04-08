/* subject.H
   An implementation of the Observer pattern
   based upon Andrei Alexandrescu's
   Generic<Programming> article in the
   C/C++ Users Journal of June 2005 (Vol 23, No 6)
*/

template <class E> class BaseSubject {
public:
  typedef E Event;
  struct Observer {
    virtual void Update(Event) = 0;
    virtual ~Observer() {}
  };
  typedef Observer* ObserverID;
  enum {
    attachKillsAllIters = 1,
    detachKillsCurrentIter = 1,
    detachKillsAllIters = 1
  };
  virtual bool Attach(ObserverID, Event) = 0;
  virtual bool Detach(ObserverID, Event) = 0;
  virtual void Detach(ObserverID) = 0;
  virtual void NotifyAll(Event) = 0;
  virtual ~BaseSubject() {}
  Observer* ID2Observer(ObserverID id) {
    return id;
  }
};

template <class E> class BareboneSubject: BaseSubject<E> {
public:
  typedef typename BaseSubject<E>::Event Event;
  typedef typename BaseSubject<E>::Observer Observer;
  typedef typename BaseSubject<E>::ObserverID ObserverID;
  bool Attach(ObserverID id, Event e) {
    value_type v(e, id);
    if (find(data.begin(), data_.end(), v) != data_.end()) {
      return false;
    }
    data_.push_back(v);
    return true;
  }
  virtual bool Detach(ObserverID id, Event e) {
    const value_type v(e, id);
    const iterator i = find(data_.begin(), data_.end(), v);
    if (i == data_.end()) return false;
    data_.erase(i);
    return true;
  }
  virtual void Detach(ObserverID id) {
    for (iterator i = data_.begin(); i != data_.end(); )
      i = i->second==id ? data_.erase(i) : i+1;
  }
  virtual void NotifyAll(Event e) {
    for (iterator i = data_.beginn(); i != data_.end(); ++i)
      if (i->first == e)
	i->second->Update(e);
  }
private:
  typedef pair<Event, ObserverID> value_type;
  typedef vector<value_type> container;
  container data_;
protected:
  typedef typename container::iterator iterator;
  iterator begin(Event) { return data_.begin(); }
  iterator end(Event) { return data_.end(); }
};
