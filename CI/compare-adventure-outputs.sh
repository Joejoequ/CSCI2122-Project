#!/bin/bash

levelAWC=$(cat level_alive | wc -l)
levelADF=$(diff level_alive level_alive_expected | wc -l)
levelDWC=$(cat level_dead | wc -l)
levelDDF=$(diff level_dead level_dead_expected | wc -l)

powerAWC=$(cat power_alive | wc -l)
powerADF=$(diff power_alive power_alive_expected | wc -l)
powerDWC=$(cat power_dead | wc -l)
powerDDF=$(diff power_dead power_dead_expected | wc -l)

strategyAWC=$(cat strategy_alive | wc -l)
strategyADF=$(diff strategy_alive strategy_alive_expected | wc -l)
strategyDWC=$(cat strategy_dead | wc -l)
strategyDDF=$(diff strategy_dead strategy_dead_expected | wc -l)

subtletyAWC=$(cat subtlety_alive | wc -l)
subtletyADF=$(diff subtlety_alive subtlety_alive_expected | wc -l)
subtletyDWC=$(cat subtlety_dead | wc -l)
subtletyDDF=$(diff subtlety_dead subtlety_dead_expected | wc -l)

charmWC=$(cat charm_alive | wc -l)
charmDF=$(diff charm_alive charm_alive_expected | wc -l)
charmWC=$(cat charm_dead | wc -l)
charmDF=$(diff charm_dead charm_dead_expected | wc -l)

if [ $levelADF -gt 0 ]; then
	printf "Your level program isn't producing correct output in alive."
	exit 100
fi

if [ $levelDDF -gt 0 ]; then
	printf "Your level program isn't producing correct output in dead."
	exit 101
fi
if [ $powerADF -gt 0 ]; then
	printf "Your power program isn't producing correct output in alive."
	exit 102
fi

if [ $powerDDF -gt 0 ]; then
	printf "Your power program isn't producing correct output in dead."
	exit 103
fi

if [ $strategyADF -gt 0 ]; then
	printf "Your strategy program isn't producing correct output in alive."
	exit 104
fi

if [ $strategyDDF -gt 0 ]; then
	printf "Your strategy program isn't producing correct output in dead."
	exit 105
fi
if [ $subtletyADF -gt 0 ]; then
	printf "Your subtlety program isn't producing correct output in alive."
	exit 106
fi

if [ $subtletyDDF -gt 0 ]; then
	printf "Your subtlety program isn't producing correct output in dead."
	exit 107
fi

if [ $charmADF -gt 0 ]; then
	printf "Your charm program isn't producing correct output in alive."
	exit 108
fi

if [ $charmDDF -gt 0 ]; then
	printf "Your charm program isn't producing correct output in dead."
	exit 109
fi





