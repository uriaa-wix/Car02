class ProximityFollowing: public Activity {
    StateMonitor* sm;
    DrivingController* dc;
    DriveAction* currentAction;
  public:
    ProximityFollowing(StateMonitor* s, DrivingController* d) {
      sm = s;
      dc = d;
      currentAction = new DriveAction();
    }

    void update(ms millis) {
      if (sm->frontProx < 50) {
        if (!currentAction->active()) {
          currentAction->reverse(500, 100);
        }
      }
    }

    void render(ms millis) {
      if (currentAction->active()) {
        dc->render(currentAction, millis);
      }
    }
};
