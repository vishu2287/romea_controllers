
#include "test_common.h"

// TEST CASES
TEST_F(AckermannControllerTest, testWrongConfig)
{
  // The controller should be never alive
  int secs = 0;
  while(!isControllerAlive() && secs < 5)
  {
    ros::Duration(1.0).sleep();
    secs++;
  }
  // Give up and assume controller load failure after 5 seconds
  EXPECT_GE(secs,5);
}


int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "four_wheel_steering_wrong_config_test");

  ros::AsyncSpinner spinner(1);
  spinner.start();
  int ret = RUN_ALL_TESTS();
  spinner.stop();
  ros::shutdown();
  return ret;
}
