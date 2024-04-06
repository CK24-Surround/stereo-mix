
#pragma once

namespace StereoMixCollisionProfileName
{
	inline const FName NoCollision = TEXT("NoCollision");
	inline const FName Player = TEXT("Player");
	inline const FName Projectile = TEXT("Projectile");
}

namespace StereoMixCollisionObjectChannel
{
	inline const ECollisionChannel Player = ECC_GameTraceChannel1;
}

namespace StereoMixCollisionTraceChannel
{
	inline const ECollisionChannel Action = ECC_GameTraceChannel2;
}
