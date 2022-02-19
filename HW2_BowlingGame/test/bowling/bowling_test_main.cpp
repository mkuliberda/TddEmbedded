#ifdef __cplusplus
extern "C" {
#endif

#include "unity/fixture/unity_fixture.h"

static void run_all_tests(void);

int main(int argc, const char **argv)
{
   UnityMain(argc, argv, run_all_tests);

   return 0;
}

static void run_all_tests(void)
{
   RUN_TEST_GROUP(single_bowling);
   RUN_TEST_GROUP(multi_bowling);
}

#ifdef __cplusplus
}
#endif