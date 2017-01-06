#include <QRoseEngine.Graphics/RenderSystem.hpp>

#include <QRoseEngine.Core/Components/TransformationComponent.hpp>
#include <QRoseEngine.Graphics/Components/MeshComponent.hpp>

using namespace QRose;

RenderSystem::RenderSystem(Ptr<Render> pRender, Ptr<Manager<TransformationComponent>> pTransformationComponentManager,
	Ptr<Manager<MeshComponent>> pMeshComponentManager)
	: pRender(pRender), pTransformationComponentManager(pTransformationComponentManager),
	pMeshComponentManager(pMeshComponentManager)
{
	if(pRender == nullptr)
	{
		throw std::invalid_argument("pRender == nullptr");
	}
	if(pTransformationComponentManager == nullptr)
	{
		throw std::invalid_argument("pTransformationComponentManager == nullptr");
	}
	if (pMeshComponentManager == nullptr)
	{
		throw std::invalid_argument("pMeshComponentManager == nullptr");
	}
}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::Update(double millisecondsElapsed)
{
	pRender->ClearView();
	pRender->BeginDrawing();

	Matrix4x4 viewMatrix;
	viewMatrix = viewMatrix.Translate(Vector3(0.5f, 0.0f, -3.0f));

	const std::vector<std::pair<Handle, MeshComponent>>& entitiesWithMeshes = pMeshComponentManager->GetAllComponents();
	std::vector<std::tuple<MeshComponent, TransformationComponent>> toDraw;
	toDraw.reserve(entitiesWithMeshes.size());
	for (auto& entityWithMesh : entitiesWithMeshes)
	{
		if (pTransformationComponentManager->Contains(entityWithMesh.first))
		{
			toDraw.push_back(std::make_tuple(entityWithMesh.second,
				pTransformationComponentManager->GetComponent(entityWithMesh.first)));
		}
	}
	pRender->SetViewMatrix(viewMatrix);
	for (const auto& toDrawTuple : toDraw)
	{
		const MeshComponent& meshComponent = std::get<0>(toDrawTuple);
		const TransformationComponent& transform = std::get<1>(toDrawTuple);
		Matrix4x4 modelMatrix;
		modelMatrix = modelMatrix.Translate(transform.position);
		modelMatrix = modelMatrix.Rotate(transform.rotation);
		modelMatrix = modelMatrix.Scale(transform.scale);
		pRender->DrawMesh(meshComponent.meshId, modelMatrix);
	}

	pRender->Present();
}