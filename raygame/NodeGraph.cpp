#include "NodeGraph.h"
#include <raylib.h>

std::vector<NodeGraph::Node*> NodeGraph::findPath(Node* start, Node* end)
{
	std::vector<Node*> path;
	path.push_back(start);
	path.push_back(end);
	return path;
}

void NodeGraph::drawGraph(Node* start)
{
	std::vector<Node*>* drawnList = new std::vector<Node*>();
	drawConnectedNodes(start, drawnList);
	delete drawnList;
}

void NodeGraph::drawNode(Node* node, int color)
{
	static char buffer[10];
	sprintf_s(buffer, "%.0f", node->gScore);

	//Draw the circle for the outline
	//DrawCircle(node->position.x, node->position.y, 16, RAYWHITE);
	//Draw the inner circle
	DrawCircle(node->position.x, node->position.y, 14, GetColor(color));
	//Draw the text
	//DrawText(buffer, node->position.x, node->position.y, 14, RAYWHITE);
}

void NodeGraph::drawConnectedNodes(Node* node, std::vector<Node*>* drawnList)
{
	drawNode(node);
	drawnList->push_back(node);

	//For each Edge in this node's connections
	for (Edge e : node->connections) {
		//Draw the Edge
		DrawLine(node->position.x, node->position.y, e.target->position.x, e.target->position.y, WHITE);
		//Draw the cost
		Vector2 costPos = { (node->position.x + e.target->position.x) / 2, (node->position.y + e.target->position.y) / 2 };
		static char buffer[10];
		sprintf_s(buffer, "%.0f", e.cost);
		//DrawText(buffer, costPos.x, costPos.y, 15, RAYWHITE);
		//Draw the target node
		if (std::find(drawnList->begin(), drawnList->end(), e.target) == drawnList->end()) {
			drawConnectedNodes(e.target, drawnList);
		}
	}
}
