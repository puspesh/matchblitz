//
//  Box.h
//  MatchThree
//
//  Created by kpuspesh on 6/2/13.
//
//
// Note 0,0 index on Box os bottom left
//
//  ^
//  |
//  4
//  3
//  2
//  1
//  0 1 2 3 4 ->
#ifndef MatchThree_Box_h
#define MatchThree_Box_h

#include "cocos2d.h"
#include "common.h"
#include "Tile2.h"
#include "SimpleAudioEngine.h"
#include "EventsManager.h"


USING_NS_CC;
class Box : public CCObject {
private:
    bool _lock;
    Tile2 * _swappedTileA;
    Tile2 * _swappedTileB;
    Orientation _swappingDirection;
    
    void checkWith(Orientation orient, int order);
    bool checkTilesToClear();
    void checkCombinations();
    bool runEffectSequence();
    
    int repair();
    int repairSingleColumn(int columnIndex);
    
    void doCombinations(int count, CCArray * matches, Orientation orient, int order);
    bool checkForWrappedCombination(Tile2 **object, Tile2 **newTileObj, int spawnX, int spawnY, int value);
    bool checkForUnstableTiles();
    bool checkForSpecialSwaps();
    
    bool drawBG(int x, int y);
    CCFiniteTimeAction* createPlayPieceAction(int index, int total);
    CCFiniteTimeAction* createPlayPieceSwiggle(int moves);
    CCFiniteTimeAction* createPlayPieceMovement(int moves);
    void burstTile(Tile2 *tile, float burstDelay);
    void vanishTile(Tile2 *tile);
    void playBurst(CCNode* sender, void* data);
    
public:
    CCSize size;
    CCLayer* layer;
    
    Tile2 *OutBorderTile;
    CCArray *content;
    CCArray *delayTimeContent;
    
    CCSet *readyToRemoveTiles;
    //CCSet *vanishedTiles;
    CCSet *readyToChangeTiles;
    CCArray *unstableTiles;
    
    bool initWithSize(CCSize size,int factor);
    Tile2 * objectAtX (int posX, int posY);
    
    bool isLocked();
    void lock();
    void unlock();
    
    bool check();
    void afterAllMoveDone(CCNode * sender);
    void repairCallback();
    
    void registerSwappedTiles(Tile2 * first, Tile2 * second);
    void deregisterSwappedTiles();
    void registerSwappingDirection(Orientation dir);
    void deregisterSwappingDirection();
    
    void removeSprite (CCNode * sender);
    void clearBurstDelay();
    float getMaxBurstDelay();
    
    virtual bool init();
    ~Box();
    CREATE_FUNC(Box);
};
#endif
