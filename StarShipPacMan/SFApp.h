#ifndef SFAPP_H
#define SFAPP_H

#include <memory>   // Pull in std::shared_ptr

#include <iostream> // Pull in std::cerr, std::endl
#include <list>     // Pull in list
#include <sstream>

using namespace std;

#include "SFCommon.h"
#include "SFEvent.h"
#include "SFAsset.h"

/**
 * Represents the StarshipFontana application.  It has responsibilities for
 * * Creating and destroying the app window
 * * Processing game events
 */
class SFApp {
public:
  SFApp(shared_ptr<SFWindow>);
  virtual ~SFApp();
  void    OnEvent(SFEvent &);
  void     OnExecute();
  void    OnUpdateWorld();
  void    OnRender();

  void    FireProjectile();
private:
  bool                    is_running;


  shared_ptr<SFAsset>		 background;
  shared_ptr<SFWindow>       sf_window;
  shared_ptr<SFAsset>        player;
  shared_ptr<SFBoundingBox>  app_box;
  shared_ptr<SFAsset> blockOne;
  shared_ptr<SFAsset> blockTwo;

  list<shared_ptr<SFAsset> > FriendlySpaceships;
  list<shared_ptr<SFAsset> > projectiles;
  list<shared_ptr<SFAsset> > aliens;

  int fire;
};
#endif
