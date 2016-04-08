/* account class in C++ for slide 323-8-10
 * J. Greg Davidson, 11 December 2007
 */
#include <string>
#include "printable.hpp"

struct Account: vis::Printable {
  typedef long AcctNum;			// account number or count
  typedef long long Money;		// refactor as a class
  typedef std::string AcctName;	// refactor as a class
  Account(AcctName n): name(n), balance(0), accountNumber(NextAcctNum()) {
    ++TotalNumberOfAccounts;
  }
  ~Account() { --TotalNumberOfAccounts; }
  void credit(Money m) { balance += m; }
  Money debit(Money m) { return balance < m ? 0 : (balance-=m, m); }
  AcctNum getAccountNumber() { return accountNumber; }
  Money getBalance() const { return balance; }
  AcctName getName() const { return name; }
  AcctNum getNumber() const { return accountNumber; }
  static AcctNum GetAccountCount() { return TotalNumberOfAccounts; }
  static AcctNum NextAcctNum () { return NextAccountNumber++; }
  std::ostream& print(std::ostream& os = std::cout) const;
private:
  AcctName name;
  Money balance;
  const AcctNum accountNumber;
  static AcctNum TotalNumberOfAccounts;
  static AcctNum NextAccountNumber;
};

#ifdef DEFINING
Account::AcctNum Account::TotalNumberOfAccounts = 0;
Account::AcctNum Account::NextAccountNumber = 0;
std::ostream& Account::print(std::ostream& os) const {
  return os << "Account: number=" << accountNumber
     << " name=\"" << name << "\" balance=" << balance;
}
#endif

#ifdef TESTING
#include <iostream>
void ReportNumAccts() {
  Account::AcctNum n = Account::GetAccountCount();
  std::cout << "There " << (n == 1 ? "is" : "are")
            << " " << n << " account" << (n == 1 ? "" : "s") << ".\n";  
}
int main() {
  ReportNumAccts();
  Account organist("Johannn S. Bach");
  Account humorist("PDQ Bach");
  ReportNumAccts();
  organist.credit( 9999 );    // $99.99
  humorist.credit( 99 );      // $0.99
  organist.credit( humorist.debit(1000) );
  humorist.credit( organist.debit(1000) );
  std::cout << organist << '\n';
  std::cout << humorist << '\n';
  return 0;
}
#endif
