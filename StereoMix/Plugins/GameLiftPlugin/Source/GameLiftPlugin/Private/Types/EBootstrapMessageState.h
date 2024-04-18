// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "GameLiftPluginConstants.h"

enum class EBootstrapMessageState : int
{
	NoBootstrappedMessage,
	InProgressMessage,
	FailureMessage,
	ActiveMessage
};

constexpr auto EBootstrapMessageStateFromInt(int State)
{
	if (State < static_cast<int>(EBootstrapMessageState::NoBootstrappedMessage) || State > static_cast<int>(
		EBootstrapMessageState::ActiveMessage))
	{
		return EBootstrapMessageState::NoBootstrappedMessage;
	}
	return static_cast<EBootstrapMessageState>(State);
}

inline FText EBootstrapMessageStateToString(EBootstrapMessageState State)
{
	switch (State)
	{
	case EBootstrapMessageState::NoBootstrappedMessage: return Settings::AwsAccount::kNoBootstrapMessage;
	case EBootstrapMessageState::InProgressMessage: return Settings::AwsAccount::kBootstrapInProgressMessage;
	case EBootstrapMessageState::FailureMessage: return Settings::AwsAccount::kFailedBootstrapMessage;
	case EBootstrapMessageState::ActiveMessage: return Settings::AwsAccount::kActiveBootstrapMessage;
	default:
		break;
	}
	ensure(false);

	return Settings::AwsAccount::kNoBootstrapMessage;
}

inline EBootstrapMessageState EBootstrapMessageStateFromString(const FString& StateString)
{
	if (StateString.Compare(Settings::AwsAccount::kNoBootstrapMessage.ToString()) == 0)
	{
		return EBootstrapMessageState::NoBootstrappedMessage;
	}
	if (StateString.Compare(Settings::AwsAccount::kBootstrapInProgressMessage.ToString()) == 0)
	{
		return EBootstrapMessageState::InProgressMessage;
	}
	if (StateString.Compare(Settings::AwsAccount::kFailedBootstrapMessage.ToString()) == 0)
	{
		return EBootstrapMessageState::FailureMessage;
	}
	if (StateString.Compare(Settings::AwsAccount::kActiveBootstrapMessage.ToString()) == 0)
	{
		return EBootstrapMessageState::ActiveMessage;
	}
	ensure(false);

	return EBootstrapMessageState::NoBootstrappedMessage;
}
