#include <gtest/gtest.h>
#include "../src/include/cpp98opts/cpp98opts.h"
#include "../src/include/cpp98opts/option.h"
#include "../src/include/cpp98opts/chapter.h"


TEST(Main, CreateAOption) {

    Option option = Option();
    option.addParameter("-c");

    std::string string = option.toString();
    ASSERT_EQ("\tPARAMETERS\n\t\t"
              "-c\n", string);

    option.addParameter("--client");

    string = option.toString();
    ASSERT_EQ("\tPARAMETERS\n\t\t-c, --client\n", string);

    option.addDescription("some text 1");

    string = option.toString();
    ASSERT_EQ("\tPARAMETERS\n\t\t"
              "-c, --client\n"
              "\t\t\tDESCRIPTIONS\n"
              "\t\t\to some text 1\n", string);

    option.addDescription("some text 2");

    string = option.toString();
    ASSERT_EQ("\tPARAMETERS\n\t\t"
              "-c, --client\n"
              "\t\t\tDESCRIPTIONS\n"
              "\t\t\to some text 1\n"
              "\t\t\to some text 2\n", string);

    option.addExample("--client vcan0");
    string = option.toString();
    ASSERT_EQ("\tPARAMETERS\n\t\t"
              "-c, --client\n"
              "\t\t\tDESCRIPTIONS\n"
              "\t\t\to some text 1\n"
              "\t\t\to some text 2\n"
              "\t\t\tEXAMPLES\n"
              "\t\t\to --client vcan0\n", string);

    option.addExample("-c can0");
    string = option.toString();
    ASSERT_EQ("\tPARAMETERS\n\t\t"
              "-c, --client\n"
              "\t\t\tDESCRIPTIONS\n"
              "\t\t\to some text 1\n"
              "\t\t\to some text 2\n"
              "\t\t\tEXAMPLES\n"
              "\t\t\to --client vcan0\n"
              "\t\t\to -c can0\n", string);

}

TEST(Main, CreateAChapterName) {

    Chapter chapter = Chapter("Name");
    chapter.addHeader("send and receive can messages");

    std::string string = chapter.toString();
    ASSERT_EQ("", string);

    ASSERT_TRUE(true);

}

TEST(Main, ReadParameters) {

    ASSERT_TRUE(true);
}