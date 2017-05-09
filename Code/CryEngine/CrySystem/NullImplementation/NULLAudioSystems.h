// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include <CryAudio/IAudioSystem.h>
#include <CryAudio/IObject.h>

namespace CryAudio
{
namespace Null
{
class CObject final : public IObject
{
public:

	CObject() = default;
	virtual ~CObject() override = default;

	virtual void ExecuteTrigger(ControlId const triggerId, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                             {}
	virtual void StopTrigger(ControlId const triggerId = InvalidControlId, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                             {}
	virtual void SetTransformation(CObjectTransformation const& transformation, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                        {}
	virtual void SetParameter(ControlId const parameterId, float const value, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                          {}
	virtual void SetSwitchState(ControlId const audioSwitchId, SwitchStateId const audioSwitchStateId, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override {}
	virtual void SetEnvironment(EnvironmentId const audioEnvironmentId, float const amount, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override            {}
	virtual void SetCurrentEnvironments(EntityId const entityToIgnore = 0, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                             {}
	virtual void ResetEnvironments(SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                                                     {}
	virtual void SetOcclusionType(EOcclusionType const occlusionType, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                  {}
	virtual void PlayFile(SPlayFileInfo const& playFileInfo, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                           {}
	virtual void StopFile(char const* const szFile, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                                    {}
	virtual void SetName(char const* const szName, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                                     {}
};

class CSystem final : public IAudioSystem
{
public:

	CSystem() = default;
	virtual ~CSystem() override = default;

	CSystem(CSystem const&) = delete;
	CSystem(CSystem&&) = delete;
	CSystem&              operator=(CSystem const&) = delete;
	CSystem&              operator=(CSystem&&) = delete;

	virtual void          Release() override                                                                                                                                                           {}
	virtual void          SetImpl(Impl::IImpl* const pIImpl, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                                           {}
	virtual void          LoadTrigger(ControlId const triggerId, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                                       {}
	virtual void          UnloadTrigger(ControlId const triggerId, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                                     {}
	virtual void          ExecuteTriggerEx(SExecuteTriggerData const& triggerData, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                     {}
	virtual void          ExecuteTrigger(ControlId const triggerId, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                                    {}
	virtual void          StopTrigger(ControlId const triggerId = InvalidControlId, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                    {}
	virtual void          SetParameter(ControlId const parameterId, float const value, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                 {}
	virtual void          SetSwitchState(ControlId const audioSwitchId, SwitchStateId const audioSwitchStateId, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override        {}
	virtual void          PlayFile(SPlayFileInfo const& playFileInfo, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                                  {}
	virtual void          StopFile(char const* const szFile, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                                           {}
	virtual void          ReportStartedFile(CATLStandaloneFile& standaloneFile, bool bSuccessfulyStarted, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override              {}
	virtual void          ReportStoppedFile(CATLStandaloneFile& standaloneFile, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                        {}
	virtual void          ReportFinishedEvent(CATLEvent& audioEvent, bool const bSuccess, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                              {}
	virtual void          LostFocus(SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                                                                    {}
	virtual void          GotFocus(SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                                                                     {}
	virtual void          MuteAll(SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                                                                      {}
	virtual void          UnmuteAll(SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                                                                    {}
	virtual void          StopAllSounds(SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                                                                {}
	virtual void          RefreshAudioSystem(char const* const szLevelName, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                                            {}
	virtual void          PreloadSingleRequest(PreloadRequestId const audioPreloadRequestId, bool const bAutoLoadOnly, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override {}
	virtual void          UnloadSingleRequest(PreloadRequestId const audioPreloadRequestId, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override                            {}
	virtual void          ReloadControlsData(char const* const szFolderPath, char const* const szLevelName, SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override            {}
	virtual void          AddRequestListener(void (* func)(SRequestInfo const* const), void* const pObjectToListenTo, ESystemEvents const eventMask) override                                          {}
	virtual void          RemoveRequestListener(void (* func)(SRequestInfo const* const), void* const pObjectToListenTo) override                                                                      {}
	virtual void          ExternalUpdate() override                                                                                                                                                    {}
	virtual bool          GetAudioTriggerId(char const* const szAudioTriggerName, ControlId& audioTriggerId) const override                                                                            { return true; }
	virtual bool          GetAudioParameterId(char const* const szParameterName, ControlId& parameterId) const override                                                                                { return true; }
	virtual bool          GetAudioSwitchId(char const* const szAudioSwitchName, ControlId& audioSwitchId) const override                                                                               { return true; }
	virtual bool          GetAudioSwitchStateId(ControlId const audioSwitchId, char const* const szSwitchStateName, SwitchStateId& audioSwitchStateId) const override                                  { return true; }
	virtual bool          GetAudioPreloadRequestId(char const* const szAudioPreloadRequestName, PreloadRequestId& audioPreloadRequestId) const override                                                { audioPreloadRequestId = InvalidPreloadRequestId; return true; }
	virtual bool          GetAudioEnvironmentId(char const* const szAudioEnvironmentName, EnvironmentId& audioEnvironmentId) const override                                                            { audioEnvironmentId = InvalidEnvironmentId; return true; }
	virtual char const*   GetConfigPath() const override                                                                                                                                               { return ""; }
	virtual IListener*    CreateListener() override                                                                                                                                                    { return nullptr; }
	virtual void          ReleaseListener(IListener* const pIListener) override                                                                                                                        {}
	virtual IObject*      CreateObject(SCreateObjectData const& objectData = SCreateObjectData::GetEmptyObject(), SRequestUserData const& userData = SRequestUserData::GetEmptyObject()) override      { return static_cast<IObject*>(&m_object); }
	virtual void          ReleaseObject(IObject* const pIObject) override                                                                                                                              {}
	virtual void          GetAudioFileData(char const* const szFilename, SFileData& audioFileData) override                                                                                            {}
	virtual void          GetAudioTriggerData(ControlId const audioTriggerId, STriggerData& audioTriggerData) override                                                                                 {}
	virtual void          OnLoadLevel(char const* const szLevelName) override                                                                                                                          {}
	virtual void          OnUnloadLevel() override                                                                                                                                                     {}
	virtual void          OnLanguageChanged() override                                                                                                                                                 {}
	virtual IProfileData* GetProfileData() const override                                                                                                                                              { return nullptr; }

private:

	CObject m_object;
};
} // namespace Null
} // namespace CryAudio
