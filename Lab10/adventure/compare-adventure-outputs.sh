#!/bin/bash


levelADF=$(diff level_alive level_alive_expected | wc -c)

levelDDF=$(diff level_dead level_dead_expected | wc -c)


powerADF=$(diff power_alive power_alive_expected | wc -c)

powerDDF=$(diff power_dead power_dead_expected | wc -c)


strategyADF=$(diff strategy_alive strategy_alive_expected | wc -c)

strategyDDF=$(diff strategy_dead strategy_dead_expected | wc -c)


subtletyADF=$(diff subtlety_alive subtlety_alive_expected | wc -c)

subtletyDDF=$(diff subtlety_dead subtlety_dead_expected | wc -c)


charmADF=$(diff charm_alive charm_alive_expected | wc -c)

charmDDF=$(diff charm_dead charm_dead_expected | wc -c)

if [ $levelADF -gt 0 ]; then
	printf "Your level program isn't producing correct output in alive."
	exit 100
fi

if [ $levelDDF -gt 0 ]; then
	printf "Your level program isn't producing correct output in dead."
	exit 100
fi


if [ $powerADF -gt 1 ]; then
	printf "Your power program isn't producing correct output in alive."
	exit 100
fi

if [ $powerDDF -gt 1 ]; then
	printf "Your power program isn't producing correct output in dead."
	exit 100
fi

if [ $strategyADF -gt 0 ]; then
	printf "Your strategy program isn't producing correct output in alive."
	exit 102
fi

if [ $strategyDDF -gt 0 ]; then
	printf "Your strategy program isn't producing correct output in dead."
	exit 102
fi
if [ $subtletyADF -gt 0 ]; then
	printf "Your subtlety program isn't producing correct output in alive."
	exit 102
fi

if [ $subtletyDDF -gt 0 ]; then
	printf "Your subtlety program isn't producing correct output in dead."
	exit 102
fi

if [ $charmADF -gt 0 ]; then
	printf "Your charm program isn't producing correct output in alive."
	exit 102
fi

if [ $charmDDF -gt 0 ]; then
	printf "Your charm program isn't producing correct output in dead."
	exit 102
fi





