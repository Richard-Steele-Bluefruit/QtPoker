#ifndef COMMUNITYCARDS_H
#define COMMUNITYCARDS_H

#include "cards.h"

class CommunityCards : public Cards
{
public:
    CommunityCards();

    bool AddCard(const Card *card);
};

#endif // COMMUNITYCARDS_H
