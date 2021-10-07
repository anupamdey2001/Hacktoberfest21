package com.fun;

import com.fun.noswitch.IndividualContributor;
import com.fun.noswitch.Manager;
import com.fun.switchitup.IndividualContributorRole;
import com.fun.switchitup.ManagementRole;

import java.math.BigDecimal;
import java.text.NumberFormat;
import java.util.Scanner;

public class Application {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Are you a member of management? ");
        var managementIndicator = input.nextLine();
        System.out.println("What is your annual salary? ");
        var salary = input.nextDouble();
        input.close();

        boolean memberOfManagement = "yes".equalsIgnoreCase(managementIndicator);

        NumberFormat numberFormat = NumberFormat.getCurrencyInstance();
        System.out.println("Your estimated bonus is: " + numberFormat.format(determineBonus(salary, memberOfManagement)));

        //Using Java 17 "preview language feature" - pattern matching in a switch statement
        BigDecimal bonus = memberOfManagement ? determineBonusAmount(new ManagementRole(), salary) : determineBonusAmount(new IndividualContributorRole(), salary);
        System.out.println("A different method. Your estimated bonus is: " + numberFormat.format(bonus));

    }

    private static BigDecimal determineBonus(double salary, boolean managementIndicator) {
        return managementIndicator ? new Manager().determineBonus(salary) : new IndividualContributor().determineBonus(salary);
    }

    // WARNING! this uses the Java 17 preview language feature - pattern matching in a switch statement
    private static BigDecimal determineBonusAmount(Object o, double salary) {
        //Individual contributors are awarded a 10% bonus, members of management are awarded a 25% bonus
        final double INDIVIDUAL_CONTRIBUTOR_PERCENTAGE = 0.1;
        final double MANAGER_PERCENTAGE = 0.25;

        return switch (o) {
            case IndividualContributorRole individualContributorRole -> individualContributorRole.determineBonus(INDIVIDUAL_CONTRIBUTOR_PERCENTAGE * salary);
            case ManagementRole managementRole -> managementRole.determineBonus(MANAGER_PERCENTAGE * salary);
            default -> BigDecimal.valueOf(0);
        };

    }
}
