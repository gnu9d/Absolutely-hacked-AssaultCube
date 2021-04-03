#include "hack.h"
extern bool IsVisible(vec v1, vec v2, dynent *tracer = NULL, bool SkipTags=false);
extern bool was_attack;
playerent *aimbottarget;
float enemynearestdist = 0;

VARP(autoaim, 0, 1, 1);
VARP(autoshot, 0, 1, 1);

void makeautoaim()
{
    if (aimbottarget != nullptr && !(aimbottarget->state!=CS_ALIVE) && autoaim)
    {
        vec aimbotvector;
        aimbotvector.x = aimbottarget->o.x - player1->o.x;
        aimbotvector.y = aimbottarget->o.y - player1->o.y;
        aimbotvector.z = aimbottarget->o.z - player1->o.z;
        aimbotvector.normalize();
        player1->yaw = player1->newyaw = -atan2(aimbotvector.x, aimbotvector.y) / 3.141592653589793F * 180 + 180;
        player1->pitch = player1->newpitch = atan2(aimbotvector.z, sqrt(aimbotvector.x*aimbotvector.x + aimbotvector.y*aimbotvector.y ) ) / 3.141592653589793F * 180;
        aimbottarget = nullptr;
        player1->attacking = autoshot ? true : was_attack;
    }
    else player1->attacking = was_attack;
}

void parsePlayers()
{
    if(autoaim)
    {
        enemynearestdist = 9000.0f;
        loopv(players)
        {
            playerent *pl = players[i];
            if(!pl || pl == player1) continue;
            if(isteam(player1->team, pl->team)) continue;
            if(!IsVisible(player1->o, pl->o)) continue;
            if(pl->state != CS_ALIVE) continue;
            if(pl->health <= 0) continue;
            if(pl->o.dist(player1->o) < enemynearestdist)
            {
                enemynearestdist = pl->o.dist(player1->o);
                aimbottarget = pl;
            }
        }
    }
    makeautoaim();
}

VARP(itemmagnet, 0, 0, 1);

void pickupentities()
{
    loopv(ents)
    {
        entity &e = ents[i];
        if(!e.spawned)continue;
        if(itemmagnet)
        {
            e.x = player1->o.x;
            e.y = player1->o.y;
            e.z = ((float)(1 + sinf(lastmillis / 100.0f + e.x + e.y) / 20)) + ((&world[((e.y)<<sfactor) + (e.x)])->floor + e.attr1);
            ents[i] = e;
        }
        else
        {
            vec newEntPos = vec(e.x, e.y, ((float)(1 + sinf(lastmillis / 100.0f + e.x + e.y) / 20)) + ((&world[((e.y) << sfactor) + (e.x)])->floor + e.attr1));
            if (player1->o.dist(newEntPos) < 10.0)
            {
                addmsg(SV_ITEMPICKUP, "ri", i);
            }
        }
    }
}

SVARP(spamstr, "");

VARP(voicespamcomnumber, -1, -1, 500);
VARP(spamteamswitch, 0, 0, 1);
VARP(spamsuicide, 0, 0, 1);
VARP(textspam, 0, 0, 1);

void spam()
{

    if(textspam)
        toserver(spamstr);

    if(voicespamcomnumber >= 0)
        addmsg(SV_VOICECOM, "ri", voicespamcomnumber);

    if(spamteamswitch)
    {
        addmsg(SV_SWITCHTEAM, "ri", team_tospec(player1->team));
        addmsg(SV_TRYSPAWN, "r");
    }
    if(spamsuicide)
    {
        addmsg(SV_SUICIDE, "r");
        addmsg(SV_TRYSPAWN, "r");
    }
}

void HackOnStep()
{
    parsePlayers();
    pickupentities();
    spam();
}
