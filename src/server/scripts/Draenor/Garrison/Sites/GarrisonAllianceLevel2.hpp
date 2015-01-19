////////////////////////////////////////////////////////////////////////////////
//
//  MILLENIUM-STUDIO
//  Copyright 2014-2015 Millenium-studio SARL
//  All Rights Reserved.
//
////////////////////////////////////////////////////////////////////////////////
#ifndef GARRISON_ALLIANCE_LEVEL_2_HPP_GARRISON
#define GARRISON_ALLIANCE_LEVEL_2_HPP_GARRISON

#include "../GarrisonScriptData.hpp"
#include "GarrisonMgr.hpp"
#include "GarrisonSiteBase.hpp"

namespace MS { namespace Garrison { namespace Sites
{
    /// Garrison alliance site level 2 instance map script
    class InstanceMapScript_GarrisonAllianceLevel2 : public InstanceMapScript
    {
        public:
            /// Constructor
            InstanceMapScript_GarrisonAllianceLevel2();

            /// Get an instance script instance
            /// @p_Map : Target map
            InstanceScript * GetInstanceScript(InstanceMap * p_Map) const;

    };

    /// Garrison alliance site level 2 instance script
    class InstanceScript_GarrisonAllianceLevel2 : public GarrisonSiteBase
    {
        public:
            /// Constructor
            /// @p_Map : Target map
            InstanceScript_GarrisonAllianceLevel2(Map* p_Map);
            /// Destructor
            ~InstanceScript_GarrisonAllianceLevel2();

            /// When instance script is updated
            /// @p_Diff : Time since last update
            virtual void Update(uint32 p_Diff) override;

        /// Implementation for InstanceScript
        public:
            /// When the owner enter in the garrison
            /// @p_Owner : Owner instance
            virtual void OnOwnerEnter(Player * p_Owner) override;

        /// Implementation for Interfaces::GarrisonSite
        public:
            /// When the garrison owner started a quest
            /// @p_Owner : Garrison owner
            /// @p_Quest : Started quest
            virtual void OnQuestStarted(Player * p_Owner, const Quest * p_Quest) override;
            /// When the garrison owner reward a quest
            /// @p_Owner : Garrison owner
            /// @p_Quest : Rewarded quest
            virtual void OnQuestReward(Player * p_Owner, const Quest * p_Quest) override;
            /// When the garrison owner abandon a quest
            /// @p_Owner : Garrison owner
            /// @p_Quest : Abandoned quest
            virtual void OnQuestAbandon(Player * p_Owner, const Quest * p_Quest) override;

            /// Get phase mask
            /// @p_Owner : Garrison owner
            virtual uint32 GetPhaseMask(Player * p_Owner) override;

            /// Owner can use the garrison cache ?
            /// @p_Owner : Garrison owner
            virtual bool CanUseGarrisonCache(Player * p_Owner) override;

            /// When a mission start
            /// @p_Owner     : Garrison owner
            /// @p_MissionID : Started mission ID
            /// @p_Followers : Followers on the mission
            virtual void OnMissionStart(Player * p_Owner, uint32 p_MissionID, std::vector<uint32> p_Followers) override;
            /// When a construction start, compute build time
            /// @p_Owner      : Garrison owner
            /// @p_BuildingID : Purchased building ID
            /// @p_BaseTime   : Default build time
            virtual uint32 OnPrePurchaseBuilding(Player * p_Owner, uint32 p_BuildingID, uint32 p_BaseTime) override;
            /// When a construction start
            /// @p_Owner      : Garrison owner
            /// @p_BuildingID : Purchased building ID
            virtual void OnPurchaseBuilding(Player * p_Owner, uint32 p_BuildingID) override;
            /// When a building is activated
            /// @p_Owner      : Garrison owner
            /// @p_BuildingID : Purchased building ID
            virtual void OnBuildingActivated(Player * p_Owner, uint32 p_BuildingID) override;

    };

}   ///< namespace Sites
}   ///< namespace Garrison
}   ///< namespace MS

#endif  ///< GARRISON_ALLIANCE_LEVEL_2_HPP_GARRISON