#!/bin/bash

levelAWC=$(cat level_alive | wc -c)
levelADF=$(diff level_alive level_alive_expected | wc -c)
levelDWC=$(cat level_dead | wc -c)
levelDDF=$(diff level_dead level_dead_expected | wc -c)

powerAWC=$(cat power_alive | wc -c)
powerADF=$(diff power_alive power_alive_expected | wc -c)
powerDWC=$(cat power_dead | wc -c)
powerDDF=$(diff power_dead power_dead_expected | wc -c)

strategyAWC=$(cat strategy_alive | wc -c)
strategyADF=$(diff strategy_alive strategy_alive_expected | wc -c)
strategyDWC=$(cat strategy_dead | wc -c)
strategyDDF=$(diff strategy_dead strategy_dead_expected | wc -c)

subtletyAWC=$(cat subtlety_alive | wc -c)
subtletyADF=$(diff subtlety_alive subtlety_alive_expected | wc -c)
subtletyDWC=$(cat subtlety_dead | wc -c)
subtletyDDF=$(diff subtlety_dead subtlety_dead_expected | wc -c)

charmWC=$(cat charm_alive | wc -c)
charmDF=$(diff charm_alive charm_alive_expected | wc -c)
charmWC=$(cat charm_dead | wc -c)
charmDF=$(diff charm_dead charm_dead_expected | wc -c)

if [ $levelADF -gt 0 ]; then
	printf "Your level program isn't producing correct output in alive."
	exit 100
fi

if [ $levelDDF -gt 0 ]; then
	printf "Your level program isn't producing correct output in dead."
	exit 100
fi
if [ $powerADF -gt 0 ]; then
	printf "Your power program isn't producing correct output in alive."
	exit 102
fi

if [ $powerDDF -gt 0 ]; then
	printf "Your power program isn't producing correct output in dead."
	exit 102
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





