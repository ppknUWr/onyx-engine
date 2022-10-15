#include "AssetsContainer.hpp"

#include <filesystem>
#include <regex>

#include "Log.hpp"

AssetsContainer::AssetsContainer() 
    : m_isDirectory(false),
      m_currentPath({ASSETS_DIRECTORY_INPUT})
{
}


AssetsContainer::~AssetsContainer()
{
    // Delete everything.
}

void AssetsContainer::CollectAssets(const std::string &path, bool createOutputDirectory)
{
    if (std::filesystem::exists(path))
    {
        for (const auto &entry : std::filesystem::directory_iterator(path))
        {
            if (std::filesystem::is_directory(entry))
            {
                // TODO: Maybe us std::format?
                auto directory_path = path + std::filesystem::path(entry).filename().generic_string() + "/";
                if (createOutputDirectory)
                {
                    CreateOutputDirectory(directory_path);
                }
                CollectAssets(directory_path, createOutputDirectory);
            }
            else
            {
                auto file_path = path + std::filesystem::path(entry).filename().generic_string();
                m_files.push_back(std::move(file_path));
            }
        }
    }
    else
    {
        LOG("Path does not exists.");
    }
}

void AssetsContainer::PrintFoundFiles()
{
    for (const auto &file : m_files)
    {
        LOG("File path: ", file);
    }
}

int AssetsContainer::Size() const
{
    return m_files.size();
}

const std::vector<std::string> &AssetsContainer::GetPathes() const
{
    return m_files;
}

void AssetsContainer::CreateOutputDirectory(const std::string &path)
{
    std::string outputPath = std::regex_replace(path, std::regex(ASSETS_DIRECTORY_INPUT), ASSETS_DIRECTORY_OUTPUT);
    if (!std::filesystem::exists(outputPath))
    {
        std::filesystem::create_directory(outputPath);
    }
}