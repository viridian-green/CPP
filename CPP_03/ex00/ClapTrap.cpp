#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name(""), HitPoints(10), EnergyPoints(10), AttackDamage(10){}

ClapTrap::~ClapTrap();

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), HitPoints(other.HitPoints), AttackDamage(other.AttackDamage){}