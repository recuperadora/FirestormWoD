////////////////////////////////////////////////////////////////////////////////
//
//  MILLENIUM-STUDIO
//  Copyright 2014-2015 Millenium-studio SARL
//  All Rights Reserved.
//
////////////////////////////////////////////////////////////////////////////////
#ifndef GARRISON_LUNARFALL_EXCAVATION_ALLIANCE_HPP_GARRISON
#define GARRISON_LUNARFALL_EXCAVATION_ALLIANCE_HPP_GARRISON

#include "../../GarrisonScriptData.hpp"
#include "../../GarrisonNPC.hpp"
#include "../GatheringBuilding.hpp"
#include "GarrisonMgr.hpp"

namespace MS { namespace Garrison 
{
    namespace LunarfallExcavation
    {
        enum Type
        {
            NPCTextThimothyLeens = 87264
        };
    }

    /// Herbs game object entries
    extern std::vector<uint32> g_AllyDepositsEntry;

    /// FarmSimulator/GoatSimulator positions
    extern std::vector<GatheringPlotInfos> g_AllyMineDeposits;

    //////////////////////////////////////////////////////////////////////////
    /// 77730 - Timothy Leens                                              ///
    //////////////////////////////////////////////////////////////////////////

    class npc_TimothyLeensAI : public GatheringBuildingMaster<&g_AllyMineDeposits>
    {
        public:
            /// Constructor
            npc_TimothyLeensAI(Creature* p_Creature);

            virtual void OnSetPlotInstanceID(uint32 p_PlotInstanceID) override;

            /// Select game object entry for a fresh gathering spawn
            /// @p_MiscData : Misc data
            virtual uint32 SelectGameObjectEntryForGatheringSpawn(uint32 p_MiscData) override;

            virtual void DoAction(int32 const p_Param) override;
    };

    class npc_TimothyLeens : public CreatureScript
    {
        public:
            /// Constructor
            npc_TimothyLeens();

            /// Called when a player opens a gossip dialog with the GameObject.
            /// @p_Player     : Source player instance
            /// @p_Creature   : Target GameObject instance
            virtual bool OnGossipHello(Player* p_Player, Creature* p_Creature) override;

            /// Called when a player selects a gossip item in the creature's gossip menu.
            /// @p_Player   : Source player instance
            /// @p_Creature : Target creature instance
            /// @p_Sender   : Sender menu
            /// @p_Action   : Action
            virtual bool OnGossipSelect(Player* p_Player, Creature* p_Creature, uint32 p_Sender, uint32 p_Action) override;

            virtual bool OnQuestReward(Player* p_Player, Creature* p_Creature, const Quest* p_Quest, uint32 p_Option) override;

            static std::vector<SequencePosition> CalculateDepositsPositions();

            static void SummonDeposits(std::vector<SequencePosition> p_SpawnPos, GarrisonNPCAI* l_AI);

            /// Called when a CreatureAI object is needed for the creature.
            /// @p_Creature : Target creature instance
            CreatureAI* GetAI(Creature* p_Creature) const;
    };

}   ///< namespace Garrison
}   ///< namespace MS

#endif  ///< GARRISON_LUNARFALL_EXCAVATION_ALLIANCE_HPP_GARRISON