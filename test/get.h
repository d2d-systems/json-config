#pragma once

#include <gtest/gtest.h>

#include <json_config.h>

#include <filesystem>
#include <optional>

class Get : public ::testing::Test
{
protected:
    static auto
    getConfigContent()
    {
        ::nlohmann::json refSetting =
        {{"KeyA", 42},
         {"KeyB", "ValueB"},
         {"KeyC", true},
         {"KeyD", {1, 2, 3, 4}},
         {"KeyE", {"E1", "E2", "E3", "E4"}},
         {"KeyF",
          {{"KeyA", 42},
           {"KeyB", "ValueB"},
           {"KeyC", true},
           {"KeyD", {1, 2, 3, 4}},
           {"KeyE", {"E1", "E2", "E3", "E4"}},
           {"KeyF",
            {{"KeyA", 42},
             {"KeyB", "ValueB"},
             {"KeyC", true},
             {"KeyD", {1, 2, 3, 4}},
             {"KeyE", {"E1", "E2", "E3", "E4"}},
             {"KeyF",
              {{"KeyA", 42},
               {"KeyB", "ValueB"},
               {"KeyC", true},
               {"KeyD", {1, 2, 3, 4}},
               {"KeyE", {"E1", "E2", "E3", "E4"}}}}}}}}};
        return refSetting;
    }

    static auto
    getConfigFilename()
    {
        return std::string {"JsonConfigFile.cfg"};
    }

    static void
    SetUpTestCase()
    {
        std::ofstream file {getConfigFilename()};
        file << getConfigContent();
    }

    static void
    TearDownTestCase()
    {
        std::filesystem::remove( getConfigFilename() );
    }

    virtual void
    SetUp()
    {
    }

    virtual void
    TearDown()
    {
    }
};