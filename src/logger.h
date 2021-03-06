//
// Created by jakub on 1/10/21.
//

#pragma once

#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/file.hpp>

namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;

namespace logger
{

void init()
{
  logging::add_file_log(keywords::file_name = "sample_%N.log",
                        keywords::rotation_size = 10 * 1024 * 1024,
                        keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
                        keywords::format = "[%TimeStamp%]: %Message%" 4);

  logging::core::get()->set_filter(logging::trivial::severity >= logging::trivial::info);
}
} // namespace logger
