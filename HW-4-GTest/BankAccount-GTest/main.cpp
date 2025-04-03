#include <gtest/gtest.h>
#include "Bank.h"


TEST(BankTest, AddAccount)
{
    BankAccount testAcc;
    Bank testBank;

    testing::internal::CaptureStdout();
    testBank.AddAccount(&testAcc);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Account added succesfully.\n");
}

TEST(BankTest, GetTotalBalance)
{
    Bank testBank;
    double sum1 = 100;
    double sum2 = -1000;
    double sum3 = 10000000000;

    BankAccount acc1("1", sum1, "Shvets Vladimir");
    BankAccount acc2("2", sum2, "Shvets Vladimir");
    BankAccount acc3("3", sum3, "Shvets Vladimir");

    double result = testBank.GetTotalBalance();
    EXPECT_EQ(result, 0);
    testBank.AddAccount(&acc1);
    result = testBank.GetTotalBalance();
    EXPECT_EQ(result, sum1);
    testBank.AddAccount(&acc2);
    result = testBank.GetTotalBalance();
    double ans = sum1 + sum2;
    EXPECT_EQ(result, ans);
    testBank.AddAccount(&acc3);
    result = testBank.GetTotalBalance();
    ans += sum3;
    EXPECT_EQ(result, ans);
}

TEST(BankTest, PrintAllAccounts)
{
    BankAccount testAcc;
    Bank testBank;

    testBank.AddAccount(&testAcc);
    testing::internal::CaptureStdout();
    testBank.PrintAllAccounts();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Bank Accounts infprmation:\n_____________________________\nAccount Number: none\nOwner: none\nBalance: 0\n");
}


TEST(BankAccauntTest, Deposit)
{
    BankAccount testAcc;
    double sum1 = 100.6;
    double sum2 = -1000;
    double sum3 = 10000000000.12;

    int exit_code = testAcc.Deposit(sum1);
    EXPECT_EQ(exit_code, 0);
    double result = testAcc.GetBalance();
    EXPECT_EQ(result, sum1);

    testing::internal::CaptureStdout();
    exit_code = testAcc.Deposit(sum2);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Error: Amount must be > 0 \n");
    EXPECT_EQ(exit_code, 1);
    result = testAcc.GetBalance();
    EXPECT_EQ(result, sum1);

    exit_code = testAcc.Deposit(sum3);
    EXPECT_EQ(exit_code, 0);
    result = testAcc.GetBalance();
    double ans = sum1 + sum3;
    EXPECT_EQ(result, ans);
}

TEST(BankAccauntTest, Withdraw)
{
    BankAccount testAcc;
    double sum1 = 100.6;
    double sum2 = -1000;
    double sum3 = 10000000000.12;

    testAcc.Deposit(1000);
    

    int exit_code = testAcc.Withdraw(sum1);
    EXPECT_EQ(exit_code, 0);
    double result = testAcc.GetBalance();
    double ans = 1000 - sum1;
    EXPECT_EQ(result, ans);

    testing::internal::CaptureStdout();
    exit_code = testAcc.Withdraw(sum3);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Error:  Not enough funds.\n");
    EXPECT_EQ(exit_code, 1);
    result = testAcc.GetBalance();
    EXPECT_EQ(result, ans);

    exit_code = testAcc.Withdraw(sum2);
    EXPECT_EQ(exit_code, 0);
    result = testAcc.GetBalance();
    ans -= sum2;
    EXPECT_EQ(result, ans);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv); // Инициализация Google Test
    return RUN_ALL_TESTS(); // Запуск всех тестов
}