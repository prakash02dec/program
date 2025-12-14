cmake_minimum_required(VERSION 3.0.0)
project(Account_Exceptional VERSION 0.1.0)

# include(CTest)
# enable_testing()

add_executable(Account_Exceptional main.cpp Savings_Account.cpp  Account_Util.cpp Account.cpp Checking_Account.cpp Trust_Account.cpp I_Printable.cpp)
target_compile_features(Account_Exceptional PRIVATE cxx_std_17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
