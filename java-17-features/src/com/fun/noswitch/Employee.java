package com.fun.noswitch;

import java.math.BigDecimal;

// In Supervisor.java - if you uncomment the block of code,
// the compiler complains because SupervisorRole extends Employee, but this is not a permitted class.

/**
 * This is no longer a preview feature! It will be a standard language feature in Java 17.
 */
sealed class Employee permits IndividualContributor, Manager {
    BigDecimal determineBonus(double salary) {
        return BigDecimal.valueOf(0);
    }
}
