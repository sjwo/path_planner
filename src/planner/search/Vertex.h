#ifndef SRC_VERTEX_H
#define SRC_VERTEX_H

#include <memory>
#include <path_planner/State.h>
#include "Edge.h"
#include "../common/Path.h"

#define HEURISTIC "maxD"

class Edge;
class Vertex {
public:

    /**
     * Construct the root vertex (no parent edge).
     * @param state the starting state
     */
    Vertex(State state);

    /**
     * Construct a non-root vertex. Not for external use.
     * @param state the underlying state
     * @param parent the parent edge
     */
    Vertex(State state, const std::shared_ptr<Edge>& parent);

    /**
     * Create a new vertex with underlying state @next, and an edge between @start and the new vertex.
     * Use this instead of any constructors for non-root vertices.
     * @param start the starting vertex
     * @param next the ending state
     * @return a vertex connected by a new edge to @start
     */
    static std::shared_ptr<Vertex> connect(const std::shared_ptr<Vertex>& start, const State& next);

    ~Vertex();

    std::shared_ptr<Vertex> parent() const;

    bool isRoot() const;

    /**
     * Estimate the heuristic value at a given state, assuming we don't cover anything along this edge to it.
     * Why would this be useful? We'll see I guess
     * @param destination the destination state
     * @return an estimate of the heuristic value at that state (from here)
     */
    double estimateApproxToGo(const State& destination);

    double computeApproxToGo();

    void setState(const State& state);

    void setParentEdge(const std::shared_ptr<Edge>& parentEdge);

    void setUncovered(const Path& uncovered);

    State& state();

    const std::shared_ptr<Edge>& parentEdge() const;

    Path& uncovered();

    double currentCost() const;

    double approxToGo();

    int getDepth() const;
private:
    State m_State;
    std::shared_ptr<Edge> m_ParentEdge; // vertex owns its parent edge
    Path m_Uncovered;
    double m_CurrentCost = -1;
    double m_ApproxCost;
    double m_ApproxToGo;
};


#endif //SRC_VERTEX_H
