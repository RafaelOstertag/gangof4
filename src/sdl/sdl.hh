#ifndef __SDL_HH
#define __SDL_HH

class SDL {
  public:
    static void initialize();
    static void shutdown();

    static bool isInitialized() { return initialized; }
    static bool hasSound() { return soundAvailable; }

  private:
    static bool initialized;
    static bool soundAvailable;
};

#endif
