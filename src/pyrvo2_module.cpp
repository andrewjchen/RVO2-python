#include <boost/python/class.hpp>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include "RVOSimulator.h"
// #include "HRVO.h"
#include "Vector2.h"
// #include "Goal.h"
// #include "Simulator.h"

namespace RVO {
 
    BOOST_PYTHON_MODULE(pyrvo2)
    {
        using namespace boost::python;
        // def("say_hello", say_hello);
        class_<RVO::Vector2>("Vector2",  init<float, float>())
        	.def("x", &RVO::Vector2::x)
        	.def("y", &RVO::Vector2::y)
        	// .def("setX", &RVO::Vector2::setX)
        	// .def("setY", &RVO::Vector2::setY)
        ;

        class_<RVO::Line>("Line",  init<>())
            .def_readwrite("point", &RVO::Line::point)
            .def_readwrite("direction", &RVO::Line::direction)
            // .def("setX", &RVO::Vector2::setX)
            // .def("setY", &RVO::Vector2::setY)
        ;
        
        // via http://www.boost.org/doc/libs/1_55_0/libs/python/doc/tutorial/doc/html/python/functions.html
        // unsigned long (hrvo::Simulator::*addAgent0)(hrvo::Vector2 &, unsigned long) = &hrvo::Simulator::addAgent;
        // bool (hrvo::*addAgent1)(hrvo::Vector2, std::size_t, float, std::size_t, float, float, float, float, float, float, float, float, hrvo::Vector2, float)      = &hrvo::addAgent;
        // TODO not working. In the meantime, remove overloading by renaming.

        //via http://stackoverflow.com/questions/10142417/boostpython-compilation-fails-because-copy-constructor-is-private
        //via http://stackoverflow.com/questions/1571054/boost-python-how-to-return-by-reference
        class_<RVO::RVOSimulator>("RVOSimulator", init<>())
            .def(init<float,float,size_t,float,float,float,float,Vector2&>())
            .def("addAgent0", &RVO::RVOSimulator::addAgent0)
            .def("addAgent1", &RVO::RVOSimulator::addAgent1)
            .def("addObstacle", &RVO::RVOSimulator::addObstacle)
            .def("addObstacleFromPython", &RVO::RVOSimulator::addObstacleFromPython)
            .def("doStep", &RVO::RVOSimulator::doStep)
            .def("getAgentAgentNeighbor", &RVO::RVOSimulator::getAgentAgentNeighbor)
            .def("getAgentMaxNeighbors", &RVO::RVOSimulator::getAgentMaxNeighbors)
            .def("getAgentMaxSpeed", &RVO::RVOSimulator::getAgentMaxSpeed)
            .def("getAgentNeighborDist", &RVO::RVOSimulator::getAgentNeighborDist)
            .def("getAgentNumAgentNeighbors", &RVO::RVOSimulator::getAgentNumAgentNeighbors)
            .def("getAgentNumObstacleNeighbors", &RVO::RVOSimulator::getAgentNumObstacleNeighbors)
            .def("getAgentNumORCALines", &RVO::RVOSimulator::getAgentNumORCALines)
            .def("getAgentObstacleNeighbor", &RVO::RVOSimulator::getAgentObstacleNeighbor)
            .def("getAgentORCALine", &RVO::RVOSimulator::getAgentORCALine, return_value_policy<reference_existing_object>())
            .def("getAgentPosition", &RVO::RVOSimulator::getAgentPosition, return_value_policy<reference_existing_object>())
            .def("getAgentPrefVelocity", &RVO::RVOSimulator::getAgentPrefVelocity, return_value_policy<reference_existing_object>())
            .def("getAgentRadius", &RVO::RVOSimulator::getAgentRadius)
            .def("getAgentTimeHorizon", &RVO::RVOSimulator::getAgentTimeHorizon)
            .def("getAgentTimeHorizonObst", &RVO::RVOSimulator::getAgentTimeHorizonObst)
            .def("getAgentVelocity", &RVO::RVOSimulator::getAgentVelocity, return_value_policy<reference_existing_object>())
            .def("getGlobalTime", &RVO::RVOSimulator::getGlobalTime)
            .def("getNumAgents", &RVO::RVOSimulator::getNumAgents)
            .def("getNumObstacleVertices", &RVO::RVOSimulator::getNumObstacleVertices)
            .def("getObstacleVertex", &RVO::RVOSimulator::getObstacleVertex, return_value_policy<reference_existing_object>())
            .def("getNextObstacleVertexNo", &RVO::RVOSimulator::getNextObstacleVertexNo)
            .def("getPrevObstacleVertexNo", &RVO::RVOSimulator::getPrevObstacleVertexNo)
            .def("getTimeStep", &RVO::RVOSimulator::getTimeStep)
            .def("processObstacles", &RVO::RVOSimulator::processObstacles)
            .def("queryVisibility", &RVO::RVOSimulator::queryVisibility)
            .def("setAgentDefaults", &RVO::RVOSimulator::setAgentDefaults)
            .def("setAgentMaxNeighbors", &RVO::RVOSimulator::setAgentMaxNeighbors)
            .def("setAgentMaxSpeed", &RVO::RVOSimulator::setAgentMaxSpeed)
            .def("setAgentNeighborDist", &RVO::RVOSimulator::setAgentNeighborDist)
            .def("setAgentPosition", &RVO::RVOSimulator::setAgentPosition)
            .def("setAgentPrefVelocity", &RVO::RVOSimulator::setAgentPrefVelocity)
            .def("setAgentRadius", &RVO::RVOSimulator::setAgentRadius)
            .def("setAgentTimeHorizon", &RVO::RVOSimulator::setAgentTimeHorizon)
            .def("setAgentTimeHorizonObst", &RVO::RVOSimulator::setAgentTimeHorizonObst)
            .def("setAgentVelocity", &RVO::RVOSimulator::setAgentVelocity)
            .def("setTimeStep", &RVO::RVOSimulator::setTimeStep)
            // .def("", &RVO::RVOSimulator::)
            // .def("", &RVO::RVOSimulator::)
            // .def("", &RVO::RVOSimulator::)
            // .def("", &RVO::RVOSimulator::)
            // .def("", &RVO::RVOSimulator::)
            // .def("", &RVO::RVOSimulator::)
            // .def("", &RVO::RVOSimulator::)
            // .def("", &RVO::RVOSimulator::)
            // .def("", &RVO::RVOSimulator::)
            // .def("", &RVO::RVOSimulator::)
            // .def("", &RVO::RVOSimulator::)
            // .def("", &RVO::RVOSimulator::)
        ;
    }

}
