cmake_minimum_required(VERSION 3.0.0)
project(enter VERSION 0.1.0)

# include(CTest)
# enable_testing()

add_executable(enter main.cpp Savings_Account.cpp  Account_Util.cpp Account.cpp Checking_Accounts.cpp Trust_Account.cpp I_Account.cpp)
target_compile_features(enter PRIVATE cxx_std_17)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
