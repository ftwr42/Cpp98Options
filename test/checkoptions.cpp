#include <gtest/gtest.h>
#include "../src/include/cpp98opts/cpp98opts.h"
#include "../src/include/cpp98opts/option.h"
#include "../src/include/cpp98opts/chapter.h"

TEST(Main, CreateAOption) {

    Cpp98Opts opts;

    Option option = opts.createOrGetOption("--parameter");
    ASSERT_EQ("--parameter\n", option.toString());

    option.addParameter("-p");
    ASSERT_EQ("--parameter, -p\n", option.toString());

    option.addDescription("creates a parameter");
    ASSERT_EQ("--parameter, -p\t\tcreates a parameter\n", option.toString());

    option.addDescription("and another one");
    ASSERT_EQ("--parameter, -p\t\t- creates a parameter\n"
                             "\t\t- and another one\n", option.toString());

    option.addExample("with one example");
    ASSERT_EQ("--parameter, -p\t\t- creates a parameter\n"
                             "\t\t- and another one\n"
                             "\t\to with one example\n", option.toString());

    option.addExample("with two example");
    ASSERT_EQ("--parameter, -p\t\t- creates a parameter\n"
                             "\t\t- and another one\n"
                             "\t\to with one example\n"
                             "\t\to with two example\n", option.toString());
}

TEST(Main, CreateAOptionWith2Parameter) {

    Cpp98Opts opts;

    Option option = opts.createOrGetOption("--parameter", "-p");
    ASSERT_EQ("--parameter, -p\n", option.toString());

    option.addDescription("creates a parameter");
    ASSERT_EQ("--parameter, -p\t\tcreates a parameter\n", option.toString());

    option.addDescription("and another one");
    ASSERT_EQ("--parameter, -p\t\t- creates a parameter\n"
                             "\t\t- and another one\n", option.toString());

    option.addExample("with one example");
    ASSERT_EQ("--parameter, -p\t\t- creates a parameter\n"
                             "\t\t- and another one\n"
                             "\t\to with one example\n", option.toString());

    option.addExample("with two example");
    ASSERT_EQ("--parameter, -p\t\t- creates a parameter\n"
                             "\t\t- and another one\n"
                             "\t\to with one example\n"
                             "\t\to with two example\n", option.toString());
}

TEST(Main, CreateAChapter) {

    Cpp98Opts opts;

    Option &option1 = opts.createOrGetOption("--parameter", "-p");
    option1.addDescription("creates a parameter");
    option1.addDescription("and another one");
    option1.addExample("with one example");
    option1.addExample("with two example");

    Option &option2 = opts.createOrGetOption("--garameter", "-g");
    option2.addDescription("creates a garameter");
    option2.addDescription("and another gone");
    option2.addExample("with one gexample");
    option2.addExample("with two gexample");

    Chapter &chapter = opts.createOrGetChapter("Chapter Header");
    ASSERT_EQ("CHAPTER HEADER\n", chapter.toString());

    chapter.addHeader("a header is here");
    ASSERT_EQ("CHAPTER HEADER\n"
              "a header is here\n", chapter.toString());

    chapter.addHeader("two header is here");
    ASSERT_EQ("CHAPTER HEADER\n"
              "a header is here\n"
              "two header is here\n", chapter.toString());

    chapter.addOption(option1);
    ASSERT_EQ("CHAPTER HEADER\n"
              "a header is here\n"
              "two header is here\n"
              "--parameter, -p\t\t- creates a parameter\n"
                             "\t\t- and another one\n"
                             "\t\to with one example\n"
                             "\t\to with two example\n", chapter.toString());

    chapter.addOption(option2);
    ASSERT_EQ("CHAPTER HEADER\n"
              "a header is here\n"
              "two header is here\n"
              "--parameter, -p\t\t- creates a parameter\n"
                             "\t\t- and another one\n"
                             "\t\to with one example\n"
                             "\t\to with two example\n"
              "--garameter, -g\t\t- creates a garameter\n"
                             "\t\t- and another gone\n"
                             "\t\to with one gexample\n"
                             "\t\to with two gexample\n", chapter.toString());

    chapter.addFooter("one line footer");
    ASSERT_EQ("CHAPTER HEADER\n"
              "a header is here\n"
              "two header is here\n"
              "--parameter, -p\t\t- creates a parameter\n"
                             "\t\t- and another one\n"
                             "\t\to with one example\n"
                             "\t\to with two example\n"
              "--garameter, -g\t\t- creates a garameter\n"
                             "\t\t- and another gone\n"
                             "\t\to with one gexample\n"
                             "\t\to with two gexample\n"
              "one line footer\n", chapter.toString());

    chapter.addFooter("two line footer");
    ASSERT_EQ("CHAPTER HEADER\n"
              "a header is here\n"
              "two header is here\n"
              "--parameter, -p\t\t- creates a parameter\n"
                             "\t\t- and another one\n"
                             "\t\to with one example\n"
                             "\t\to with two example\n"
              "--garameter, -g\t\t- creates a garameter\n"
                             "\t\t- and another gone\n"
                             "\t\to with one gexample\n"
                             "\t\to with two gexample\n"
              "one line footer\n"
              "two line footer\n", chapter.toString());
}

TEST(Main, AddChapterToCpp98opts) {

    Cpp98Opts cpp98opts;

    Option &option1 = cpp98opts.createOrGetOption("--string", "-s");
    option1.addDescription("enter a string");
    option1.addExample("something like this");

    Option &option2 = cpp98opts.createOrGetOption("--array", "-a");
    option2.addDescription("enter a array");
    option2.addExample("1,2,3,4");

    Option &option3 = cpp98opts.createOrGetOption("--int", "-i");
    option3.addDescription("enter a int");
    option3.addExample("42");

    Option &option4 = cpp98opts.createOrGetOption("--hex", "-h");
    option4.addDescription("a hex digit like following");
    option4.addExample("1, 42, 0A, A, AA, FF");

    Option &option5 = cpp98opts.createOrGetOption("--severalMixed", "-sm");
    option5.addDescription("mix of different types div by <space>");
    option5.addExample("1");

    std::vector<std::string> signs;
    signs.push_back("/path/of/program");

    signs.push_back("--string");
    signs.push_back("HelloWorld");

    signs.push_back("--int");
    signs.push_back("42");

    signs.push_back("--array");
    signs.push_back("1,2,3,4");

    signs.push_back("--hex");
    signs.push_back("1");
    signs.push_back("42");
    signs.push_back("0A");
    signs.push_back("A");
    signs.push_back("AA");
    signs.push_back("FF");

    signs.push_back("--severalMixed");
    signs.push_back("1");
    signs.push_back("Hey");
    signs.push_back("2,3");
    signs.push_back("Hello,World");
    signs.push_back("A");

    cpp98opts.readParameters(signs);

    ASSERT_EQ(true, cpp98opts.getInput("--int")[0].asBool());
    ASSERT_EQ(42, cpp98opts.getInput("--int")[1].asInt());
    ASSERT_EQ(true, cpp98opts.getInput("-i")[0].asBool());
    ASSERT_EQ(42, cpp98opts.getInput("-i")[1].asInt());

    ASSERT_EQ(true, cpp98opts.getInput("--string")[0].asBool());
    ASSERT_EQ("HelloWorld", cpp98opts.getInput("--string")[1].asString());
    ASSERT_EQ(true, cpp98opts.getInput("-s")[0].asBool());
    ASSERT_EQ("HelloWorld", cpp98opts.getInput("-s")[1].asString());

    ASSERT_EQ(true, cpp98opts.getInput("--array")[0].asBool());
    ASSERT_EQ(1, cpp98opts.getInput("--array")[1].asVector()[0]->asInt());
    ASSERT_EQ("1", cpp98opts.getInput("--array")[1].asVector()[0]->asString());
    ASSERT_EQ(2, cpp98opts.getInput("--array")[1].asVector()[1]->asInt());
    ASSERT_EQ("2", cpp98opts.getInput("--array")[1].asVector()[1]->asString());
    ASSERT_EQ(3, cpp98opts.getInput("--array")[1].asVector()[2]->asInt());
    ASSERT_EQ("3", cpp98opts.getInput("--array")[1].asVector()[2]->asString());
    ASSERT_EQ(4, cpp98opts.getInput("--array")[1].asVector()[3]->asInt());
    ASSERT_EQ("4", cpp98opts.getInput("--array")[1].asVector()[3]->asString());
    ASSERT_EQ(1, cpp98opts.getInput("-a")[1].asVector()[0]->asInt());
    ASSERT_EQ("1", cpp98opts.getInput("-a")[1].asVector()[0]->asString());
    ASSERT_EQ(2, cpp98opts.getInput("-a")[1].asVector()[1]->asInt());
    ASSERT_EQ("2", cpp98opts.getInput("-a")[1].asVector()[1]->asString());
    ASSERT_EQ(3, cpp98opts.getInput("-a")[1].asVector()[2]->asInt());
    ASSERT_EQ("3", cpp98opts.getInput("-a")[1].asVector()[2]->asString());
    ASSERT_EQ(4, cpp98opts.getInput("-a")[1].asVector()[3]->asInt());
    ASSERT_EQ("4", cpp98opts.getInput("-a")[1].asVector()[3]->asString());

    ASSERT_EQ(true, cpp98opts.getInput("--hex")[0].asBool());
    ASSERT_EQ(1, cpp98opts.getInput("--hex")[1].asHexUInt());
    ASSERT_EQ(66, cpp98opts.getInput("--hex")[2].asHexUInt());
    ASSERT_EQ(10, cpp98opts.getInput("--hex")[3].asHexUInt());
    ASSERT_EQ(10, cpp98opts.getInput("--hex")[4].asHexUInt());
    ASSERT_EQ(170, cpp98opts.getInput("--hex")[5].asHexUInt());
    ASSERT_EQ(255, cpp98opts.getInput("--hex")[6].asHexUInt());
    ASSERT_EQ(true, cpp98opts.getInput("-h")[0].asBool());
    ASSERT_EQ(1, cpp98opts.getInput("-h")[1].asHexUInt());
    ASSERT_EQ(66, cpp98opts.getInput("-h")[2].asHexUInt());
    ASSERT_EQ(10, cpp98opts.getInput("-h")[3].asHexUInt());
    ASSERT_EQ(10, cpp98opts.getInput("-h")[4].asHexUInt());
    ASSERT_EQ(170, cpp98opts.getInput("-h")[5].asHexUInt());
    ASSERT_EQ(255, cpp98opts.getInput("-h")[6].asHexUInt());

    ASSERT_EQ(true, cpp98opts.getInput("--severalMixed")[0].asBool());
    ASSERT_EQ(1, cpp98opts.getInput("--severalMixed")[1].asInt());
    ASSERT_EQ("1", cpp98opts.getInput("--severalMixed")[1].asString());
    ASSERT_EQ("Hey", cpp98opts.getInput("--severalMixed")[2].asString());
    ASSERT_EQ(2, cpp98opts.getInput("--severalMixed")[3].asVector()[0]->asInt());
    ASSERT_EQ("2", cpp98opts.getInput("--severalMixed")[3].asVector()[0]->asString());
    ASSERT_EQ(3, cpp98opts.getInput("--severalMixed")[3].asVector()[1]->asInt());
    ASSERT_EQ("3", cpp98opts.getInput("--severalMixed")[3].asVector()[1]->asString());
    ASSERT_EQ("Hello", cpp98opts.getInput("--severalMixed")[4].asVector()[0]->asString());
    ASSERT_EQ("World", cpp98opts.getInput("--severalMixed")[4].asVector()[1]->asString());
    ASSERT_EQ("A", cpp98opts.getInput("--severalMixed")[5].asString());
    ASSERT_EQ(10, cpp98opts.getInput("--severalMixed")[5].asHexUInt());
    ASSERT_EQ(true, cpp98opts.getInput("-sm")[0].asBool());
    ASSERT_EQ(1, cpp98opts.getInput("-sm")[1].asInt());
    ASSERT_EQ("1", cpp98opts.getInput("-sm")[1].asString());
    ASSERT_EQ("Hey", cpp98opts.getInput("-sm")[2].asString());
    ASSERT_EQ(2, cpp98opts.getInput("-sm")[3].asVector()[0]->asInt());
    ASSERT_EQ("2", cpp98opts.getInput("-sm")[3].asVector()[0]->asString());
    ASSERT_EQ(3, cpp98opts.getInput("-sm")[3].asVector()[1]->asInt());
    ASSERT_EQ("3", cpp98opts.getInput("-sm")[3].asVector()[1]->asString());
    ASSERT_EQ("Hello", cpp98opts.getInput("-sm")[4].asVector()[0]->asString());
    ASSERT_EQ("World", cpp98opts.getInput("-sm")[4].asVector()[1]->asString());
    ASSERT_EQ("A", cpp98opts.getInput("-sm")[5].asString());
    ASSERT_EQ(10, cpp98opts.getInput("-sm")[5].asHexUInt());
}

TEST(Main, CheckDependencies12) {
    Cpp98Opts opts;

    Option &option1 = opts.createOrGetOption("-o1", "--option1");
    option1.addDescription("this one can stand alone");
    option1.addExample("--option1");

    Option &option2 = opts.createOrGetOption("-o2", "--option2");
    option2.addDescription("this one depends on option1");
    option2.addExample("--option2 --option1");
    option2.addExample("--option1 --option2");

    option2.addDependsOn(option1);

    std::vector<std::string> signs;
    signs.push_back("/path/of/program");
    signs.push_back("--option1");
    signs.push_back("--option2");

    EXPECT_NO_THROW({
        opts.readParameters(signs);
    });
}

TEST(Main, CheckDependencies21) {

    Cpp98Opts opts;

    Option &option1 = opts.createOrGetOption("-o1", "--option1");
    option1.addDescription("this one can stand alone");
    option1.addExample("--option1");

    Option &option2 = opts.createOrGetOption("-o2", "--option2");
    option2.addDescription("this one depends on option1");
    option2.addExample("--option2 --option1");
    option2.addExample("--option1 --option2");

    option2.addDependsOn(option1);

    std::vector<std::string> signs;
    signs.push_back("/path/of/program");
    signs.push_back("--option2");
    signs.push_back("--option1");

    EXPECT_NO_THROW({
        opts.readParameters(signs);
    });
}

TEST(Main, CheckDependencies1) {

    Cpp98Opts opts;

    Option &option1 = opts.createOrGetOption("-o1", "--option1");
    option1.addDescription("this one can stand alone");
    option1.addExample("--option1");

    Option &option2 = opts.createOrGetOption("-o2", "--option2");
    option2.addDescription("this one depends on option1");
    option2.addExample("--option2 --option1");
    option2.addExample("--option1 --option2");

    option2.addDependsOn(option1);

    std::vector<std::string> signs;
    signs.push_back("/path/of/program");
    signs.push_back("--option1");

    EXPECT_NO_THROW({
        opts.readParameters(signs);
    });
}

TEST(Main, CheckDependencies2) {

    Cpp98Opts opts;

    Option option1 = opts.createOrGetOption("-o1", "--option1");
    option1.addDescription("this one can stand alone");
    option1.addExample("--option1");

    Option &option2 = opts.createOrGetOption("-o2", "--option2");
    option2.addDescription("this one depends on option1");
    option2.addExample("--option2 --option1");
    option2.addExample("--option1 --option2");

    option2.addDependsOn(option1);

    std::vector<std::string> signs;
    signs.push_back("/path/of/program");
    signs.push_back("--option2");

    EXPECT_THROW({
        opts.readParameters(signs);
    }, std::runtime_error);
}

TEST(Changes, MapToVectorOptions) {

    //in order to make the map in cpp98opts more easy and tranform it into an vector
    //the user should not handle smart_ptr and so on. Theirfor Cpp98Opts do need to handle everything
    //factory like

    Cpp98Opts cpp98opts;

    //1) create a datatype to hold the options
    //2) create handlers to add and manipulate all option datas in cpp98opts
    //2.1) should be done like this

    Option &option1 = cpp98opts.createOrGetOption("-o");
    option1.addParameter("--Aoption");
    option1.addDescription("Adescription");
    option1.addExample("Aexample");

    Option &option1_1 = cpp98opts.createOrGetOption("-o");
    option1_1.addParameter("--Boption");
    option1_1.addDescription("Bdescription");
    option1_1.addExample("Bexample");

    Option &option2 = cpp98opts.createOrGetOption("-l");
    option2.addDescription("description");
    option2.addExample("example");

    //3) in order to not create a circle with chapter, cpp98opts also handles getChapter
    //3.1) to add a option to chapter this will be done like this as well, if it does not exist yet
    //     it will be created as well

    Chapter &chapter = cpp98opts.createOrGetChapter("Header of this Chapter");
    chapter.addHeader("header message");
    chapter.addOption(option1);
    chapter.addFooter("footer message");
}
